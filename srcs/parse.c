/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:11:35 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 19:56:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static const t_f_formatter	g_printfuncs[] = {
	&ft_printchar,
	&ft_printstr
};

static short int	ft_get_formdata(const char **str)
{
	char		modgroup;
	t_e_format	format;
	char		form_start;

	if (!str || !*str)
		return (NULL_ERROR);
	modgroup = 0;
	format = FORMAT_NONE;
	form_start = FORM_INDICATOR;
	while (!format)
	{
		if (form_start == FORM_INDICATOR && ft_ismod(**str))
			modgroup = ft_modify(modgroup, ft_get_modidifier(**str));
		else if (form_start == FORM_INDICATOR && ft_isformat(**str))
			format = ft_get_format(**str);
		else
			form_start = **str;
		if (form_start != FORM_INDICATOR && format != FORMAT_NONE)
			return (FORMAT_ERROR);
		(*str)++;
	}
	return (ft_printf_data(modgroup, format));
}

ssize_t	ft_parse(const char *str, va_list valist)
{
	t_s_buffer	*buffer_char;
	size_t		i;
	short int	formdata;

	buffer_char = ft_buffinit();
	i = 0;
	formdata = 0;
	while (str[i])
	{
		if (str[i] == FORM_INDICATOR)
		{
			formdata = ft_get_formdata(&str);
			if (formdata < 0)
				return (PARSE_ERROR);
			g_printfuncs[formdata % FORMAT_SIZE](formdata, buffer_char, valist);
		}
		ft_buffadd(buffer_char, str[i]);
		i++;
	}
	ft_buffclose(buffer_char);
	return (NO_ERROR);
}
