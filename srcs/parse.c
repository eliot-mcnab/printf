/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:11:35 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 18:30:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static const t_f_formatter	g_printfuncs[] = {
	&ft_printchar,	  /* handles charcacter display                           */
	&ft_printstr,     /* handles string display                               */
	&ft_printptr,     /* handles pointer display                              */
	&ft_printint,     /* handles decimal display                              */
	&ft_printint,     /* handles int display                                  */
	&ft_printuint,    /* handles unsigned int display                         */
	&ft_printhex_s,   /* handles small caps hex display                       */
	&ft_printhex_b,   /* handles big caps hex display                         */
	&ft_printind,     /* handles percentage display                           */
};

/**
 * @brief Calculates the formdata bytes of a fomat section in a printf string.
 *
 * Formdata is composed of two bytes, where the first bytes holds a hash of the
 * modifiers associated to the format and the second byte contains the index of
 * the format.
 *
 * @param str (char **): reference to the string being parsed, must point to a
 *        FORM_INDICATOR.
 *
 * @return (short int): formdata hash associated to the format startning at 
 *         FORM_INDICATOR. Will be negative if a format error occurred (invalid
 *         format).
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
static short int	ft_get_formdata(const char **str)
{
	char		modgroup;
	t_e_format	format;
	char		form_start;

	if (!str || !*str)
		return (NULL_ERROR);
	if (!**str)
		return (FORMAT_ERROR);
	(*str)++;
	modgroup = 0;
	format = FORMAT_NONE;
	form_start = FORM_INDICATOR;
	while (format == FORMAT_NONE)
	{
		if (form_start == FORM_INDICATOR && ft_ismod(**str))
			modgroup = ft_modify(modgroup, ft_get_modidifier(**str));
		else if (form_start == FORM_INDICATOR && ft_isformat(**str))
			format = ft_get_format(**str);
		else
			form_start = **str;
		if (form_start != FORM_INDICATOR && format == FORMAT_NONE)
			return (FORMAT_ERROR);
		(*str)++;
	}
	return (ft_printf_data(modgroup, format));
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
ssize_t	ft_parse(const char *str, va_list valist)
{
	t_s_buffer	*buffer;
	short int	formdata;

	buffer = ft_buffinit();
	formdata = 0;
	while (*str)
	{
		if (*str == FORM_INDICATOR)
		{
			formdata = ft_get_formdata(&str);
			if (formdata < 0)
			{
				ft_buffclose(buffer);
				return (PARSE_ERROR);
			}
			g_printfuncs[formdata % FORMAT_SIZE](formdata, buffer, valist);
		}
		if (ft_buffadd(buffer, *str) < 0)
			return (WRITE_ERROR);
		if (*str)
			str++;
	}
	return (ft_buffclose(buffer));
}
