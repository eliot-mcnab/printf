/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:21:59 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 12:01:23 by emcnab           ###   ########.fr       */
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
 * @param (short int): hash containing the modifers applied to the formatter and
 *        the formatter's index.
 * @param valist (va_list): variable argument list used to retrieve the
 *        character.
 *
 * @return (ssize_t): error code.
 *
 * @see ft_parse(const char *, va_list)
 * @see ft_get_format(char)
 * @see ft_modify(char, t_e_modifier)
 * @see ft_printf_data(char, t_e_format)
 * @see errors.h
 * @see parse.h
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
ssize_t	ft_printpercent(short int formdata, t_s_buffer *buffer, va_list valist)
{
	(void)formdata;
	(void)valist;
	return (ft_buffadd(buffer, FORM_INDICATOR));
}
