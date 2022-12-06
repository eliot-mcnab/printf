/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:43:57 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:26:44 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Handles string display in ft_printf.
 *
 * This function is called if ft_parse encounters a string formatter. The
 * string to insert is retrieved from [valist] and added to [buffer]. To match
 * the behavior of the orinal printf, if ever the string is NULL, will output
 * (null) instead.
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
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printstr(short int formdata, t_s_buffer *buffer, va_list valist)
{
	char	*str;

	(void) formdata;
	str = va_arg(valist, char *);
	if (!str)
		str = NULL_STR;
	return (ft_buffadd_str(buffer, str));
}
