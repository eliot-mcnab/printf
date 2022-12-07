/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:27:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 13:26:44 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file printf.h
 * @brief Simple re-implementation of printf.
 *
 * Supports the following flags:
 * - 'c': character
 * - 's': string
 * - 'd': decimal
 * - 'i': int
 * - 'u': unsigned int
 * - 'x': small caps hex code
 * - 'X': big caps hex code
 * - '%': percentage escaping
 *
 * Supports the following modifiers:
 * - '-': right-pads number with spaces
 * - '0': left-pads number with zeros
 * - '.': set floating-point precision
 * - '#': adds 0x for hex and .0 for floats
 * - '+': displays '+' in signed conversions
 * - ' ': blank before positive number in signed conversion.
 *
 * @author Eliot Mcnab
 * @date 12/06/2022
 */

#ifndef PRINTF_H
# define PRINTF_H

# include "parse.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);

#endif 
