/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formdata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:09:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 09:15:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formdata.h"

static const t_s_modinfo	g_info[6] = {
{0x1, 0x0},		/* '-' */
{0x2, 0x1},		/* '0' */
{0x4, 0x0},		/* '.' */
{0x8, 0x0},		/* '#' */
{0x10, 0x0},	/* '+' */
{0x20, 0x10}	/* '-' */
};

/**
 * @brief Combines the [format] byte and modifier bytes into 32 bits, where the
 * 	first byte corresponds to [format] and the second to [modgroup].
 *
 * @param format (char): byte representation of the format to use in a printf
 * 	call.
 * @param modgroup (char): byte representation of the modifiers used in a printf
 * 	call.
 *
 * return (short int): 32-bit representation containing both the [format] and
 * 	[modgroup] bytes.
 */
short int	ft_printf_data(char format, char modgroup)
{
	return ((short int)((format << 8) | modgroup));
}

/**
 * @brief Converts a [format] to a single bit in a byte.
 *
 * @param format (t_format): the format to convert to a byte.
 *
 * @return (char): byte representation of [format].
 */
char	ft_format(t_e_format format)
{
	return ((char)(1 << format));
}

/**
 * @brief Adds a [modifier] to a [modgroup] if the [modgroup] does not already
 * 	contain a modifier which is incompatible.
 *
 * @param modgroup (char): byte representing all modifiers in a printf call.
 * @param modifier (t_modifier): the modifier to add.
 *
 * @return (char): modgroup with the new modifier if there were no comflicts.
 */
char	ft_modify(char modgroup, t_e_modifier modifier)
{
	t_s_modinfo	modinfo;

	modinfo = g_info[modifier];
	if (!(modgroup & modinfo.conflics))
		return (modgroup | modinfo.modifer);
	return (modgroup);
}
