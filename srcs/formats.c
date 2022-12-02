/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:53:59 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/02 11:39:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formats.h"
/**
 * @brief Converts a [format] to a single bit in a byte.
 *
 * @param format (t_format): the format to convert to a byte.
 *
 * @return (char): byte representation of [format].
 */
char	ft_format(t_format format)
{
	return (1 << format);
}
