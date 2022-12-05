/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:11:35 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 15:22:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static short int	ft_get_formdata(const char **str, t_s_buffer *buffer)
{
	char	modgroup;
	char	format;
	char	current;

	modgroup = 0;
	format = 0;
	current = '\0';
	while (!format)
	{
		ft_buffadd(buffer, **str);
		if (current == '%' && ft_ismod(**str))
			modgroup = ft_modify(modgroup, ft_get_modidifier(**str));
		else if (current == '%' && ft_isformat(**str))
			format = ft_get_format(**str);
		else
			current = '%';
		if (current != '%' && !format)
			return (FORMAT_ERROR);
		(*str)++;
	}
	return (ft_printf_data(format, modgroup));
}

ssize_t	ft_parse(const char *str, va_list valist)
{
	t_s_buffer	*buffer_char;
	size_t		i;
	short int	formdata;

	buffer_char = ft_buffinit();
	i = 0;
	while (str[i])
	{
		formdata = ft_get_formdata(&str, buffer_char) < 0;
		if (formdata < 0)
			return (PARSE_ERROR);
		i++;
	}
	ft_buffclose(buffer_char);
	return (i);
}
