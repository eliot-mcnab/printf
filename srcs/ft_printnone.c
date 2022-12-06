/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:26:51 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 18:32:53 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Dummy format function for ft_printf.
 *
 * This function is called if ft_parse encounters a formatter which has not yet
 * been implemented, adding "[formatter not implemented yet]" to the buffer. 
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
ssize_t	ft_printnone(short int formdata, t_s_buffer *buffer, va_list valist)
{
	(void) formdata;
	(void) valist;
	return (ft_buffadd_str(buffer, "[formatter not implemented yet]"));
}
