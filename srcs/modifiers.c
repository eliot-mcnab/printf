/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:09:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/02 11:38:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/modifiers.h"

static const t_modinfo	g_info[6] = {
{0x1, 0x0},		/* '-' */
{0x2, 0x1},		/* '0' */
{0x4, 0x0},		/* '.' */
{0x8, 0x0},		/* '#' */
{0x10, 0x0},	/* '+' */
{0x20, 0x10}	/* '-' */
};

/**
 * @brief Adds a [modifier] to a [modgroup] if the [modgroup] does not already
 * 	contain a modifier which is incompatible.
 *
 * @param modgroup (char): byte representing all modifiers in a printf call.
 * @param modifier (t_modifier): the modifier to add.
 *
 * @return (char): modgroup with the new modifier if there were no comflicts.
 */
char	ft_modify(char modgroup, t_modifier modifier)
{
	t_modinfo	modinfo;

	modinfo = g_info[modifier];
	if (!(modgroup & modinfo.conflics))
		return (modgroup | modinfo.modifer);
	return (modgroup);
}
