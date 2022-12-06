/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:03:48 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 18:10:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

ssize_t	ft_printhex_s(short int formdata, t_s_buffer *buffer, va_list valist)
{
	char	*str_hex;
	ssize_t	error_code;

	(void) formdata;
	str_hex = ft_itoa_base(va_arg(valist, long), "0123456789abcdef");
	if (!str_hex)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(buffer, str_hex);
	free(str_hex);
	return (error_code);
}
