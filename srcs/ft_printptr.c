/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:56:27 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/08 09:21:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Handles pointer display in ft_printf.
 *
 * This function is called if ft_parse encounters a pointer formatter. The
 * pointer to insert is retrieved from [valist] and added to [buffer], preceded
 * by 0x0. To match the behavior of the orinal printf, if ever the pointer is
 * NULL, will output (nill) instead. Conversion to hexadecimal is done using the
 * ft_itoa_base(long, char) function from libft.
 *
 * @param printdata (t_s_printdata *): strucutre containing the data used to
 *        display format.
 *
 * @return (ssize_t): error code.
 * 
 * @return (ssize_t): error code.
 *
 * @see ft_parse(const char *, va_list)
 * @see ft_printf_data(char, t_e_format)
 * @see ft_itoa_base(long, char)
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printptr(t_s_printdata *printdata)
{
	unsigned long	ptr;
	char			*str_ptr;
	ssize_t			error_code;

	ptr = va_arg(*printdata->valist, unsigned long);
	if (!ptr)
		return (ft_buffadd_str(printdata->buffer, NULL_PTR));
	str_ptr = ft_ultoa_base(ptr, SMALL_HEX_BASE);
	if (!str_ptr)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(printdata->buffer, "0x");
	error_code = (ft_buffadd_str(printdata->buffer, str_ptr) && error_code);
	free(str_ptr);
	return (error_code);
}
