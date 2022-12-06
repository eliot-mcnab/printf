/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:08:10 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:54:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

/**
 * @brief Determnines if a characterb buffer is full.
 *
 * @param buffer (t_s_buffer *): buffer to check.
 *
 * @return (bool): true if buffer is full, false otherwise.
 *
 * @author Eliot McNab
 * @date 12/05/2022
 */
bool	ft_buffull(t_s_buffer *buffer)
{
	return (buffer-> i >= (sizeof(t_lword) - 1));
}

/*
 * @brief Determnines if a longword buffer is full.
 *
 * @param buffer (t_s_buffer_long *): buffer to check.
 *
 * @return (bool): true if buffer is full, false otherwise.
 *
 * @author Eliot McNab
 * @date 12/05/2022
 */
/* bool	ft_buffull_long(t_s_buffer_long *buffer)
{
	return (buffer->i >= LBUFFER_SIZE);
} */
