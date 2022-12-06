/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:56:27 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 18:45:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 *
 */
ssize_t	ft_printptr(short int formdata, t_s_buffer *buffer, va_list valist)
{
	void	*ptr;
	char	*str_ptr;
	ssize_t	error_code;

	(void) formdata;
	ptr = va_arg(valist, void *);
	if (!ptr)
		return (ft_buffadd_str(buffer, "(nil)"));
	str_ptr = ft_itoa_base((long)ptr, "0123456789abcdef");
	if (!str_ptr)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(buffer, "0x");
	error_code = (ft_buffadd_str(buffer, str_ptr) && error_code);
	free(str_ptr);
	return (error_code);
}
