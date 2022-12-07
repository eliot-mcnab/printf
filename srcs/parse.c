/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:11:35 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 14:13:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void	ft_parse_moddata(const char **str, t_e_modifier mod, int *moddata)
{
	while (ft_isdigit(**str))
	{
		moddata[mod] = moddata[mod] * 10 + ft_todigit(**str);
		(*str)++;
	}
	(*str)--;
}

static short int	ft_parse_formdata(const char **str, int *moddata)
{
	char			modgroup;
	t_e_format		format;
	t_e_modifier	modifier;

	if (!str || !*str)
		return (FORMAT_NONE);
	modgroup = 0;
	format = INDICATOR;
	modifier = MODIFIER_NONE;
	while (format == INDICATOR)
	{
		if (ft_ismod(**str))
		{
			modifier = ft_get_modidifier(**str);
			modgroup = ft_modify(modgroup, modifier);
		}
		else if (ft_isdigit(**str))
			ft_parse_moddata(str, modifier, moddata);
		else
			format = ft_get_format(**str);
		(*str)++;
	}
	return (ft_formdata(modgroup, format) * (format != FORMAT_NONE));
}

static t_s_printdata	*ft_parse_printdata(
		const char **str,
		int *moddata,
		va_list *valist,
		t_s_buffer *buffer)
{
	short int	formatdata;

	if (!str || !*str)
		return (NULL);
	(*str)++;
	formatdata = ft_parse_formdata(str, moddata);
	if (!formatdata)
		return (NULL);
	return (ft_printdata(formatdata, moddata, valist, buffer));
}

/**
 * @brief Parses a string fop FORM_INDICATORs and replaces those by the
 *        specified format.
 *
 * Whenever a FORM_INDICATOR is found, tries to extract the format directly
 * after it. Format is displayed usiong a custom function for that format.
 * Parsing stops when the end of the string has been reached or a error has
 * occurred. These can be a PARSE_ERROR if an invalid format was detected or a
 * WRITE_ERROR if buffer was unable to write to STDOUT.
 *
 * @param str (const char *): the format sting to parse.
 * @param valist (va_list): list of arguments passed to ft_printf.
 *
 * @see ft_printf(2) errors.h formatters.h
 */
ssize_t	ft_parse(const char *str, va_list *valist)
{
	t_s_buffer		*buffer;
	int				moddata[MODIFIER_SIZE];
	t_s_printdata	*printdata;

	buffer = ft_buffinit();
	ft_bzero(moddata, MODIFIER_SIZE * sizeof(*moddata));
	printdata = 0;
	while (*str)
	{
		if (*str == FORM_INDICATOR)
		{
			printdata = ft_parse_printdata(&str, moddata, valist, buffer);
			if (!printdata)
			{
				ft_buffclose(buffer);
				return (PARSE_ERROR);
			}
			ft_apply_format(printdata);
			free(printdata);
		}
		if (ft_buffadd(buffer, *str) < 0)
			return (WRITE_ERROR);
		str += (*str != '\0');
	}
	return (ft_buffclose(buffer));
}
