/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:23 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:27:23 by emcnab           ###   ########.fr       */
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

# define SMALL_HEX_BASE "0123456789abcdef"
# define BIG_HEX_BASE   "0123456789ABCDEF"
# define NULL_STR       "(null)"
# define NULL_PTR       "(nil)"

typedef ssize_t	(*t_f_formatter)(short int, t_s_buffer*, va_list);

ssize_t	ft_printchar(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printstr(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printptr(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printint(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printuint(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printhex_s(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printhex_b(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printind(short int formdata, t_s_buffer *buffer, va_list valist);
ssize_t	ft_printnone(short int formdata, t_s_buffer *buffer, va_list valist);

#endif
