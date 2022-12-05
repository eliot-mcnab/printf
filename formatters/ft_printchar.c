/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:32:19 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 15:47:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

ssize_t	ft_printchar(short int formdata, t_s_buffer *buffer, va_list valist)
{
	if (ft_buffadd(buffer, (char) va_arg(valist, int)) < 0)
		return (WRITE_ERROR);
	return (NO_ERROR);
}
