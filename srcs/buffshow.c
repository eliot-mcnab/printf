/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffshow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:57:28 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/03 17:24:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/buffer.h"

void	ft_buffshow(t_s_buffer *buffer)
{
	size_t	i;
	t_lword	*str_current;
	t_lword	*str_previous;

	if (!buffer)
		return ;
	i = buffer->i;
	str_previous = buffer->data;
	while (i > 0)
	{
		str_current = ft_lword_search(str_previous, '\0');
		i -= (size_t)(str_current - buffer->data);
		// TODO: ft_putstr_fd should inform of write failure
		ft_putstr_fd((char *)str_previous, STDOUT);
		str_previous = str_current++;
	}
}
