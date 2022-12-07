/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:21:59 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 12:33:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"
#include "../includes/parse.h"

/**
 * @brief Handles FORM_INDICATOR display in ft_printf.
 *
 * This function is called if ft_parse encounters a FORM_INDICATOR and adds it
 * to [buffer].
 *
 * @param printdata (t_s_printdata *): strucutre containing the data used to
 *        display format.
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
ssize_t	ft_printind(t_s_printdata *printdata)
{
	return (ft_buffadd(printdata->buffer, FORM_INDICATOR));
}
