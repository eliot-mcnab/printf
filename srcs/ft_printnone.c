/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:26:51 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 09:29:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

ssize_t	ft_printnone(short int formdata, t_s_buffer *buffer, va_list valist)
{
	(void) formdata;
	(void) valist;
	return (ft_buffadd_str(buffer, "[formatter not implemented yet]"));
}
