/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bufflush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:57:28 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 17:29:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

/**
 * @brief Flushes the contents of a character buffer to STDOUT.
 *
 * Displays all the character added to the buffer, resetting its index to 0 and
 * null-terminating it. Any other data is not deleted for performace reasons but
 * is set up for rewriting by resetting index.
 *
 * @param buffer (t_s_buffer *): the buffer to flush
 *
 * @return (ssize_t): error code.
 * @see error.h
 *
 * @author Eliot McNab
 * @date 12/05/2022
 */
ssize_t	ft_bufflush(t_s_buffer *buffer)
{
	if (!ft_putstr_fd(buffer->data, STDOUT))
		return (WRITE_ERROR);
	buffer->written += buffer->i;
	buffer->i = 0;
	buffer->data[0] = '\0';
	return (NO_ERROR);
}

/*
 * @brief Flushes the contents of a longword buffer to STDOUT.
 *
 * Displays all the bytes added to the buffer, resetting its index to 0 and
 * null-terminating it. Any other data is not deleted for performace reasons but
 * is set up for rewritting by resetting index.
 *
 * @param buffer (t_s_buffer_long *): the buffer to flush.
 *
 * @return (ssize_t): error code.
 * @see errors.h
 *
 * @author Eliot McNab
 * @date 12/05/2022
 */
/* ssize_t	ft_bufflush_long(t_s_buffer_long *buffer)
{
	t_lword	*str_current;
	t_lword	*str_previous;

	if (!buffer)
		return (NULL_ERROR);
	str_previous = buffer->data;
	while (buffer->i)
	{
		str_current = ft_lword_search(str_previous, '\0');
		buffer->i -= (size_t)(str_current - buffer->data);
		if (ft_putstr_fd((char *)str_previous, STDOUT) < 0)
			return (WRITE_ERROR);
		str_previous = str_current++;
	}
	buffer->data[0] = 0x0;
	return (NO_ERROR);
} */
