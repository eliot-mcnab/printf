/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:25:01 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/09 10:29:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/**
 * @brief Simple re-implementation of printf.
 *
 * Supports the following flags:
 * - 'c': character
 * - 's': string
 * - 'p': pointer
 * - 'd': decimal
 * - 'i': int
 * - 'u': unsigned int
 * - 'x': small caps hex code
 * - 'X': big caps hex code
 * - '%': percentage escaping
 *
 * @author Eliot Mcnab
 * @date 12/06/2022
 */
int	ft_printf(const char *str, ...)
{
	va_list	valist;
	ssize_t	written;

	va_start(valist, str);
	written = ft_parse(str, &valist);
	va_end(valist);
	return ((int) written);
}
