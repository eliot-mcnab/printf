/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formdata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:33:13 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 12:15:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file formdata.h
 * @brief Handles format/modifier validation and binary representation.
 * @author Eliot McNab
 * @date 12/06/2022
 */

#ifndef MODIFIERS_H
# define MODIFIERS_H

# include "types.h"
# include "libft.h"

/**
 * @brief represents a format character in a printf call.
 */
typedef enum e_format
{
	CHARACTER,  /**< used to display a single ascii charcter                  */
	STRING,     /**< used to display a string                                 */
	POINTER,    /**< used to display a pointer adress                         */
	DECIMAL,    /**< used to display a base 10 decimal number                 */
	INT,        /**< used to display a base 10 integer number                 */
	UINT,       /**< used to display a base 10 unsigned integer number        */
	SMALL_HEX,  /**< used to display a hexadecimal number in small caps       */
	BIG_HEX,    /**< used to display a hexadecimal number in big caps         */
	PERCENTAGE, /**< escaped % sign                                           */
	FORMAT_SIZE,/**< number of formats stored in t_e_format                   */
	FORMAT_NONE /**< placeholder format, used as error flag or temp value     */
}	t_e_format;

t_e_format		ft_get_format(char c);
bool			ft_isformat(char c);

/**
 * @brief represents the various modifers that be applied to printf.
 */
typedef enum e_modifier
{
	R_PADDING,    /**< '-' : right-pads number with spaces                    */
	L_PADDING,    /**< '0' : left-pads number with zeros                      */
	PRECISION,    /**< '.' : set floating-point precision                     */
	ALT_FORM,     /**< '#' : adds 0x for hex and .0 to floats                 */
	FORCE_SIGN,   /**< '+' : display '+' in signed conversion                 */
	BLANK_SIGN,   /**< ' ' : blank before positive number in signed conversion*/
	MODIFIER_SIZE,/**< number of modifiers stored in t_e_modifier             */
	MODIFIER_NONE /**< placeholder modifier, used as error flag or temp value */
}	t_e_modifier;

/**
 * @brief Represents information attached to a modifier, used for comparison
 *        between modifiers and conversion to byte-form representation.
 */
typedef struct s_modinfo
{
	char	modifer;	/**< byte pattern representing the modifier            */
	char	conflics;	/**< byte pattern representing uncompatible modifier   */
}	t_s_modinfo;

short int		ft_printf_data(char modgroup, t_e_format format);
char			ft_modify(char modgroup, t_e_modifier modifier);
t_e_modifier	ft_get_modidifier(char c);
bool			ft_ismod(char c);

#endif
