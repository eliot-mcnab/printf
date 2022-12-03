/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffshow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:57:28 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/03 17:20:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

void	ft_buffshow(t_s_buffer *buffer)
{
	t_lword	*str_current;
	t_lword	*str_previous;

	if (!buffer)
		return ;
	str_previous = buffer->data;
	while (buffer->i > 0)
	{
		str_current = ft_lword_search(str_previous, '\0');
		buffer->i -= (size_t)(str_current - buffer->data);
		// TODO: ft_putstr_fd should inform of write failure
		ft_putstr_fd((char *)str_previous, STDOUT);
		str_previous = str_current++;
	}
}
