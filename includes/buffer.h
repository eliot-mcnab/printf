/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:31:44 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 10:04:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <stdlib.h>
# include "types.h"
# include "libft.h"

/**
 * @struct t_s_buffer
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
typedef struct s_buffer
{
	size_t	i;
	t_lword	data[BUFFER_SIZE / sizeof(t_lword) + 1];
}	t_s_buffer;

t_s_buffer	*ft_buffinit(void);
void		ft_buffshow(t_s_buffer *buffer);

#endif
