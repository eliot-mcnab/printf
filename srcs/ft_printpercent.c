/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:21:59 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 09:23:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

ssize_t	ft_printpercent(short int formdata, t_s_buffer *buffer, va_list valist)
{
	(void)formdata;
	(void)valist;
	return (ft_buffadd(buffer, '%'));
}
