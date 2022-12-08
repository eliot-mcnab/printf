/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:09:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/08 11:40:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formdata.h"

/**
 * @brief Combines the [format] byte and modifier bytes into 32 bits, where the
 *        first byte corresponds to [modgroup] and the second to [format].
 *
 * @param format (char): byte representation of the format to use in a printf
 *        call.
 * @param modgroup (char): byte representation of the modifiers used in a printf
 *        call.
 *
 * return (short int): 32-bit representation containing both the [format] and
 *        [modgroup] bytes.
 *
 * @author Eliot McNab
 * @date 12/05/2022
 */
short int	ft_formdata(char modgroup, t_e_format format)
{
	return ((short int)(((unsigned int) modgroup << 8) | format));
}

/**
 * @brief Stores all values needed by formatter functions into a single
 *        structure.
 *
 * @param formdata (short int): bitwise representation of a format and its
 *        modifiers.
 * @param moddata (int *): values associated to each modifer in [formdata].
 * @param valist (va_list *): variable argument list of values to format.
 * @param buffer (t_s_buffer *): buffer used to display format.
 *
 * @author Eliot McNab
 * @date 12/08/2022
 */
t_s_printdata	*ft_printdata(
		short int formdata,
		int *moddata,
		va_list *valist,
		t_s_buffer	*buffer
	)
{
	t_s_printdata	*printdata;

	printdata = malloc(sizeof(*printdata));
	if (!printdata || !moddata || !valist || !buffer)
		return (NULL);
	printdata->formdata = formdata;
	printdata->moddata = moddata;
	printdata->valist = valist;
	printdata->buffer = buffer;
	return (printdata);
}
