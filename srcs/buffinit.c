/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:32:52 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:52:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

/**
 * @brief Creates a new character buffer instance.
 *
 * Buffer will have its index set to 0 and its data will be null-terminated at
 * the first byte to avoid accidental traversal of non-initialised values.
 *
 * @return (t_s_buffer): new buffer instance.
 */
t_s_buffer	*ft_buffinit(void)
{
	t_s_buffer	*buffer;

	buffer = malloc(sizeof(*buffer));
	if (!buffer)
		return (NULL);
	buffer->i = 0;
	buffer->data[0] = '\0';
	return (buffer);
}

/*
 * @brief Creates a new longword buffer instance.
 *
 * Buffer will have its index set to 0 and its data will be null-terminated at
 * the first byte to avoid accidental traversal of non-initialised values.
 *
 * @return (t_s_buffer_long): new buffer instance.
 */
/* t_s_buffer_long	*ft_buffinit_long(void)
{
	t_s_buffer_long	*buffer;

	buffer = malloc(sizeof(*buffer));
	if (!buffer)
		return (NULL);
	buffer->i = 0;
	buffer->data[0] = 0x0;
	return (buffer);
} */
