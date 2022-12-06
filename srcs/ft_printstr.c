/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:43:57 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 09:24:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

ssize_t	ft_printstr(short int formdata, t_s_buffer *buffer, va_list valist)
{
	(void) formdata;
	return (ft_buffadd_str(buffer, va_arg(valist, char *)));
}
