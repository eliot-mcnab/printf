/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:31:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 18:31:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Handles long display in ft_printf.
 *
 * This function is called if ft_parse encounters an unsigned integer formatter.
 * The unsigned integer to insert is retrieved from [valist] and added to
 * [buffer]. ft_ltoa(int n) is used to convert it to a string, which is then
 * added to the buffer.
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
 * @see ft_ltoa(int)
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printuint(short int formdata, t_s_buffer *buffer, va_list valist)
{
	char	*str_long;
	ssize_t	error_code;

	(void) formdata;
	str_long = ft_ltoa(va_arg(valist, unsigned int));
	if (!str_long)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(buffer, str_long);
	free(str_long);
	return (error_code);
}
