/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:25:01 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 16:38:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	valist;

	va_start(valist, str);
	if (ft_parse(str, valist) < 0)
		return (WRITE_ERROR);
	va_end(valist);
	return (NO_ERROR);
}
