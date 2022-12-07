/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:59:56 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 14:12:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"
#include <asm-generic/errno.h>

static const t_e_format		g_to_format[26] = {
	FORMAT_NONE,
	FORMAT_NONE,
	CHARACTER,	// c
	DECIMAL,	// d
	FORMAT_NONE,
	FORMAT_NONE,
	FORMAT_NONE,
	FORMAT_NONE,
	INT,		// i
	FORMAT_NONE,
	FORMAT_NONE,
	FORMAT_NONE,
	FORMAT_NONE,
	FORMAT_NONE,
	FORMAT_NONE,
	POINTER,	// p
	FORMAT_NONE,
	FORMAT_NONE,
	STRING,		// s
	FORMAT_NONE,
	UINT,		// u
	FORMAT_NONE,
	FORMAT_NONE,
	SMALL_HEX,	// x
	FORMAT_NONE,
	FORMAT_NONE
};

static const t_f_formatter	g_formfuncs[] = {
	&ft_printchar,
	&ft_printstr,
	&ft_printptr,
	&ft_printint,
	&ft_printint,
	&ft_printuint,
	&ft_printhex_s,
	&ft_printhex_b,
	&ft_printind,
};

void	ft_apply_format(t_s_printdata *printdata)
{
	g_formfuncs[(printdata->formdata & MASK) % FORMAT_SIZE](printdata);
}

/**
 * @brief Gets the format associated to a character.
 *
 * @param c (char): the chracter to get the format of.
 *
 * @return (t_e_format): format associated to [c] or FORMAT_NONE if no format
 *         was associated to [c].
 */
t_e_format	ft_get_format(char c)
{
	if (ft_islower(c))
		return (g_to_format[c - 'a']);
	else if (c == 'X')
		return (BIG_HEX);
	else if (c == '%')
		return (INDICATOR);
	return (FORMAT_NONE);
}

/**
 * @brief Determines if a character is a formatter.
 *
 * @param c (char): the character to check.
 *
 * @return (bool): true if [c] is a formatter, false otherwise.
 */
bool	ft_isformat(char c)
{
	return (ft_get_format(c) != FORMAT_NONE);
}
