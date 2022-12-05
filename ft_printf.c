/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:25:01 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 14:29:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static short int	ft_get_formdata(const char *str)
{
	size_t	i;
	char	modgroup;
	char	format;
	char	current;

	i = 0;
	modgroup = 0;
	format = 0;
	current = '\0';
	while (!format)
	{
		if (current == '%' && ft_ismod(str[i]))
			modgroup = ft_modify(modgroup, ft_get_modidifier(str[i]));
		else if (current == '%' && ft_isformat(str[i]))
			format = ft_get_format(str[i]);
		else
			current = '%';
		i++;
		if (current != '%' && modgroup)
			return (PARSE_ERROR);
	}
	return (ft_printf_data(format, modgroup));
}

ssize_t	ft_parse(const char *str, va_list valist)
{
	size_t		i;
	short int	formdata;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	t_lword	*lword;

	i = 0;
	lword = (t_lword *)str + i;
}
