/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:25:01 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 17:38:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	valist;
	ssize_t	written;

	va_start(valist, str);
	written = ft_parse(str, &valist);
	va_end(valist);
	return ((int) written);
}
