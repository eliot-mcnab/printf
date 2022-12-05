/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:09:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 14:27:28 by emcnab           ###   ########.fr       */
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
short int	ft_printf_data(char format, char modgroup)
{
	return ((short int)((modgroup << 8) | format));
}
