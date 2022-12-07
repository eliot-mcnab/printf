/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:18:40 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 18:16:24 by emcnab           ###   ########.fr       */
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
 * @param printdata (t_s_printdata *): strucutre containing the data used to
 *        display format.
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
ssize_t	ft_printhex_b(t_s_printdata *printdata)
{
	unsigned long	long_hex;
	char			*str_hex;
	ssize_t			error_code;

	long_hex = va_arg(*printdata->valist, unsigned long);
	str_hex = ft_itoa_base(long_hex, BIG_HEX_BASE);
	if (!str_hex)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(printdata->buffer, str_hex);
	free(str_hex);
	return (error_code);
}
