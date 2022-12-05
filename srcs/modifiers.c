/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:57:51 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 14:12:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formdata.h"

static char					*g_mods = "-0.#+ ";
static const t_s_modinfo	g_modinfo[6] = {
{0x1, 0x0},		/* '-' */
{0x2, 0x1},		/* '0' */
{0x4, 0x0},		/* '.' */
{0x8, 0x0},		/* '#' */
{0x10, 0x0},	/* '+' */
{0x20, 0x10}	/* ' ' */
};
static const t_e_modifier	g_to_modifier[] = {
	BLANK_SIGN,		// ' '
	MODIFIER_NONE,
	MODIFIER_NONE,
	ALT_FORM,		// '#'
	MODIFIER_NONE,
	MODIFIER_NONE,
	MODIFIER_NONE,
	MODIFIER_NONE,
	MODIFIER_NONE,
	MODIFIER_NONE,
	MODIFIER_NONE,
	FORCE_SIGN,		// '+'
	MODIFIER_NONE,
	R_PADDING,		// '-'
	PRECISION,		// '.'
	MODIFIER_NONE,
	L_PADDING		// '0'
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
char	ft_modify(char modgroup, t_e_modifier modifier)
{
	t_s_modinfo	modinfo;

	modinfo = g_modinfo[modifier];
	if (!(modgroup & modinfo.conflics))
		return (modgroup | modinfo.modifer);
	return (modgroup);
}

/**
 * @brief Gets the modifier associated to the a character.
 *
 * @param c (char): the character to get the modifier of.
 *
 * @return (t_e_modifier): modifer associated to [c] or MODIFIER_NONE if no
 *         fornat was associated to [c].
 */
t_e_modifier	ft_get_modidifier(char c)
{
	if (c >= ' ' && c <= '0')
		return (g_to_modifier[c - ' ']);
	return (MODIFIER_NONE);
}

/**
 * @brief Determines if a character is a modifer.
 *
 * @param c (char): the character to check.
 *
 * @return (bool): true if [c] is a modifier, false otherwise.
 */
bool	ft_ismod(char c)
{
	return (ft_get_modidifier(c) != MODIFIER_NONE);
}
