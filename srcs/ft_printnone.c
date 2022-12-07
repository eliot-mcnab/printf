/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:26:51 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 12:33:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

/**
 * @brief Dummy format function for ft_printf.
 *
 * This function is called if ft_parse encounters a formatter which has not yet
 * been implemented, adding "[formatter not implemented yet]" to the buffer. 
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
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printnone(t_s_printdata *printdata)
{
	return (ft_buffadd_str(printdata->buffer, TBA_STR));
}
