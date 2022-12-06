/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:32:19 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 18:30:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Handles character display in ft_printf.
 *
 * This function is called if ft_parse encounters a character formatter. The
 * character to insert is retrieved from [valist] and added to [buffer].
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
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printchar(short int formdata, t_s_buffer *buffer, va_list valist)
{
	(void) formdata;
	return (ft_buffadd(buffer, (char) va_arg(valist, int)));
}
