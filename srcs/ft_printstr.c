/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:43:57 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 12:50:24 by emcnab           ###   ########.fr       */
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
ssize_t	ft_printstr(t_s_printdata *printdata)
{
	char	*str;

	str = va_arg(*printdata->valist, char *);
	if (!str)
		str = NULL_STR;
	return (ft_buffadd_str(printdata->buffer, str));
}
