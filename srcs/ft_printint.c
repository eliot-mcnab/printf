/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:33:00 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 12:33:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Handles integer display in ft_printf.
 *
 * This function is called if ft_parse encounters an integer formatter. The
 * integer to insert is retrieved from [valist] and added to [buffer].
 * ft_itoa(int n) is used to convert the integer to a string, which is then
 * added to the buffer.
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
 * @see ft_itoa(int)
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printint(t_s_printdata *printdata)
{
	char	*str_int;
	ssize_t	error_code;

	str_int = ft_itoa(va_arg(*printdata->valist, int));
	if (!str_int)
		return (MALLOC_ERROR);
	error_code = ft_buffadd_str(printdata->buffer, str_int);
	free(str_int);
	return (error_code);
}
