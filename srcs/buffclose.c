/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:13:42 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:53:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

/**
 * @brief Flushes all the contents of a character buffer and frees it.
 *
 * @param buffer (t_s_buffer *): the buffer to close.
 *
 * @return (ssize_t): error code.
 */
ssize_t	ft_buffclose(t_s_buffer *buffer)
{
	if (!buffer)
		return (ARG_ERROR);
	ft_bufflush(buffer);
	free(buffer);
	return (NO_ERROR);
}

/*
 * @brief Flushes all the contents of a long buffer and frees it.
 *
 * @param buffer (t_s_buffer_long *): the buffer to close.
 *
 * @return (ssize_t): error code.
 */
/* ssize_t	ft_buffclose_long(t_s_buffer_long *buffer)
{
	if (!buffer)
		return (ARG_ERROR);
	ft_buffclose_long(buffer);
	free(buffer);
	return (NO_ERROR);
} */
