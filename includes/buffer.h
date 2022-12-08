/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:31:44 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/08 12:13:13 by emcnab           ###   ########.fr       */
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
 * @brief A buffer of characters used by printf to store and display characters
 *        while a string is still no aligned with t_longword.
 *
 * Implements naive flush tactic, where formatted strings are allocated and only
 * then added to buffer, displayed and freed. This allows to more easily reuse
 * libft functions but might change at a later date once a first working
 * prototype has been created.
 */
typedef struct s_buffer
{
	size_t	i;                 /**< (size_t): current index in the buffer.    */
	ssize_t	written;           /**< (size_t): total number of chars written.  */
	char	data[BUFFER_SIZE]; /**< (char *): data contained by the buffer.   */
}	t_s_buffer;

t_s_buffer		*ft_buffinit(void);
bool			ft_buffull(t_s_buffer *buffer);
ssize_t			ft_bufflush(t_s_buffer *buffer);
ssize_t			ft_buffadd(t_s_buffer *buffer, char c);
ssize_t			ft_buffadd_str(t_s_buffer *buffer, char *str);
ssize_t			ft_buffclose(t_s_buffer *buffer);

/*
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
 */
/* typedef struct s_lbuffer
{
	size_t	i;
	t_lword	data[LBUFFER_SIZE + 1];
}	t_s_buffer_long;

t_s_buffer_long	*ft_buffinit_long(void);
ssize_t			ft_bufflush_long(t_s_buffer_long *buffer);
bool			ft_buffull_long(t_s_buffer_long *buffer);
ssize_t			ft_buffadd_long(t_s_buffer_long *buffer, t_lword lword);
ssize_t			ft_buffclose_long(t_s_buffer_long *buffer); */

#endif
