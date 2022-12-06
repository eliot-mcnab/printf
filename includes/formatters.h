/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:23 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 09:34:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file formatters.h
 * @brief Holds sub-functions used by ft_printf to display various types.
 * @author Eliot McNab
 * @date 12/05/2022
 * @see ft_printf(2)
 *
 * Functions must follow all have the signature (short int, t_s_buffer, va_list)
 * to allow for packing inside of a single array.
 */

#ifndef FORMATTERS_H
# define FORMATTERS_H

# include "buffer.h"
# include <stdarg.h>

typedef ssize_t	(*t_f_formatter)(short int, t_s_buffer*, va_list);

ssize_t	ft_printchar(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printstr(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printpercent(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printnone(short int formdata, t_s_buffer *buffer, va_list valist);

#endif