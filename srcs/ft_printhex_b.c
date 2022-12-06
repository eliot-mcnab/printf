/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:18:40 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:13:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Handles big hex display in ft_printf.
 *
 * This function is called if ft_parse encounters a big hex formatter. The
 * hex value to insert is retrieved from [valist] and added to [buffer].
 * Conversion from long to hex is done using the ft_itoa_base function in libft.
 *
 * @param formdata (short int): hash containing the modifers applied to the 
 *        formatter and the formatter's index.
 * @param valist (va_list): variable argument list used to retrieve the
 *        character.
 *
 * @return (ssize_t): error code.
 * 
 * @return (ssize_t): error code.
 *
 * @see ft_parse(const char *, va_list)
 * @see ft_printf_data(char, t_e_format)
 * @see ft_itoa_base(long, char *)
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printhex_b(short int formdata, t_s_buffer *buffer, va_list valist)
{
	char	*str_hex;
	ssize_t	error_code;

	(void) formdata;
	str_hex = ft_itoa_base(va_arg(valist, long), "0123456789ABCDEF");
	if (!str_hex)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(buffer, str_hex);
	free(str_hex);
	return (error_code);
}
