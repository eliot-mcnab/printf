/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:31:44 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 14:58:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file buffer.h
 * @brief Holds all buffer-realted functions and structs for ft_printf.
 * @author Eliot McNab
 * @date 12/05/2022
 */

#ifndef BUFFER_H
# define BUFFER_H

# include <stdlib.h>
# include "types.h"
# include "errors.h"
# include "libft.h"

# define LBUFFER_SIZE BUFFER_SIZE / sizeof(t_lword)

/**
 * @brief t_s_buffer
 * @brief A buffer of characters used by printf to store and display characters
 *        while a string is still no aligned with t_longword.
 *
 * Implements naive flush tactic, where formatted strings are not added to
 * buffer but are rather allocated, displayed and freed. This requires buffer be
 * flushed before each format but this isn't a big deal since we will be dealing
 * with at most sizeof(t_lword) - 1 characters before the string is aligned.
 *
 * @var i (size_t): current index in the buffer.
 * @var data (char *): data contained by the buffer.
 */
typedef struct s_buffer
{
	size_t	i;
	char	data[sizeof(t_lword)];
}	t_s_buffer;

t_s_buffer		*ft_buffinit(void);
ssize_t			ft_bufflush(t_s_buffer *buffer);
bool			ft_buffull(t_s_buffer *buffer);
ssize_t			ft_buffadd(t_s_buffer *buffer, char c);

/**
 * @struct t_s_buffer_long
 * @brief A buffer of longwords used by printf to store and display multiple
 *        bytes of information at once.
 *
 * Buffer can contain up to [BUFFER_SIZE] characters, with an extra longword to
 * guarantee null-termination. Characters are considered one longword at a time,
 * which depending on system architecture is at least 8 bytes, with 16 bytes on
 * 64-bit C implementations. Note that characters MUST be added one longword at
 * a time and cannot be added seperatly. Because format strings in printf will
 * not always be sizeof(t_longword) bytes long, buffer may contain empty bytes
 * where a format string has been added. Because of this, buffer will be
 * considered as multiple null-terminated c strings upon display, until the end
 * of the buffer has been reached.
 *
 * @var i (size_t): current index in the buffer.
 * @var data (t_longword *): data contained by the buffer. 
 */
typedef struct s_lbuffer
{
	size_t	i;
	t_lword	data[LBUFFER_SIZE + 1];
}	t_s_buffer_long;

t_s_buffer_long	*ft_buffinit_long(void);
ssize_t			ft_bufflush_long(t_s_buffer_long *buffer);
bool			ft_buffull_long(t_s_buffer_long *buffer);
ssize_t			ft_buffadd_long(t_s_buffer_long *buffer, t_lword lword);

#endif
