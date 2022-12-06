/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:56:27 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:27:29 by emcnab           ###   ########.fr       */
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
 * @param formdata (short int): hash containing the modifers applied to the
 *        formatter and the formatter's index.
 * @param valist (va_list): variable argument list used to retrieve the
 *        string.
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
ssize_t	ft_printptr(short int formdata, t_s_buffer *buffer, va_list valist)
{
	void	*ptr;
	char	*str_ptr;
	ssize_t	error_code;

	(void) formdata;
	ptr = va_arg(valist, void *);
	if (!ptr)
		return (ft_buffadd_str(buffer, NULL_PTR));
	str_ptr = ft_itoa_base((long)ptr, SMALL_HEX_BASE);
	if (!str_ptr)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(buffer, "0x");
	error_code = (ft_buffadd_str(buffer, str_ptr) && error_code);
	free(str_ptr);
	return (error_code);
}
