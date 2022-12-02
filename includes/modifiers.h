/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:33:13 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/02 11:22:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODIFIERS_H
# define MODIFIERS_H

# include "types.h"

/**
 * @enum: t_modifier
 * @brief: represents the various modifers that be applied to printf.
 */
typedef enum e_modifier
{
	R_PADDING,	/*! '-' : right-pads number with spaces                       */
	L_PADDING,	/*! '0' : left-pads number with zeros                         */
	PRECISION,	/*! '.' : set floating-point precision                        */
	ALT_FORM,	/*! '#' : adds 0x for hex and .0 to floats                    */
	FORCE_SIGN,	/*! '+' : display '+' in signed conversion                    */
	BLANK_SIGN	/*! ' ' : blank before positive number in signed conversion   */
}	t_modifier;

typedef struct s_modinfo
{
	char	modifer;	/* byte pattern representing the modifier             */
	char	conflics;	/* byte pattern representing uncompatible modifier    */
}	t_modinfo;

#endif
