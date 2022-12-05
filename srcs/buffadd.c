/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:00:38 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 14:57:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

/**
 * @brief Adds a new character to a character buffer.
 *
 * Supposes that there is enough space in buffer to add [c]. If buffer is
 * full, automatically flushes it. Guarantees to null-terminate the buffer.
 *
 * @param buffer (t_s_buffer *): the buffer to add [c] to.
 * @param c (char): the character to add to [buffer].
 *
 * @return (ssize_t): error code.
 * @see errors.h
 *
 * @author Eliot McNab
 * @date 12/05/2022
 */
ssize_t	ft_buffadd(t_s_buffer *buffer, char c)
{
	if (ft_buffull(buffer) && ft_bufflush(buffer) < 0)
		return (WRITE_ERROR);
	buffer->data[buffer->i++] = c;
	buffer->data[buffer->i] = '\0';
	return (NO_ERROR);
}

/**
 * @brief Adds a new longword to a longword buffer.
 *
 * Supposes that there is enough space in buffer to add [lword]. If buffer is
 * full, automatically flushes it. Guarantees to null-terminate the buffer.
 *
 * @param buffer (t_s_buffer_long *): the buffer to add [lword] to.
 * @param lword (t_lword): the longword to add to [buffer].
 *
 * @return (ssize_t): error code.
 * @see errors.h
 *
 * @author Eliot McNab
 * @date 12/05/2022
 */
ssize_t	ft_buffadd_long(t_s_buffer_long *buffer, t_lword lword)
{
	if (ft_buffull_long(buffer) && ft_bufflush_long(buffer) < 0)
		return (WRITE_ERROR);
	buffer->data[buffer->i++] = lword;
	buffer->data[buffer->i] = 0x0L;
	return (NO_ERROR);
}
