/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatters.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:31:23 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 12:15:35 by emcnab           ###   ########.fr       */
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
# include "formdata.h"
# include <stdarg.h>

# define SMALL_HEX_BASE "0123456789abcdef"
# define BIG_HEX_BASE   "0123456789ABCDEF"
# define NULL_STR       "(null)"
# define NULL_PTR       "(nil)"
# define TBA_STR        "[formatter not implemented yet]"

typedef ssize_t	(*t_f_formatter)(t_s_printdata *);

// TODO: update doccumentation for formatters now that arguments have changed
ssize_t	ft_printchar(t_s_printdata *printdata);
ssize_t	ft_printstr(t_s_printdata *printdata);
ssize_t	ft_printptr(t_s_printdata *printdata);
ssize_t	ft_printint(t_s_printdata *printdata);
ssize_t	ft_printuint(t_s_printdata *printdata);
ssize_t	ft_printhex_s(t_s_printdata *printdata);
ssize_t	ft_printhex_b(t_s_printdata *printdata);
ssize_t	ft_printind(t_s_printdata *printdata);
ssize_t	ft_printnone(t_s_printdata *printdata);

#endif
