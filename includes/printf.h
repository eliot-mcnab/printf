/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:27:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/09 10:25:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file printf.h
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

#ifndef PRINTF_H
# define PRINTF_H

# include "parse.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);

#endif 
