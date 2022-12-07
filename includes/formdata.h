/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formdata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:33:13 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 16:44:29 by emcnab           ###   ########.fr       */
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
# include "buffer.h"
# include "libft.h"

# define MASK 0xFF

/**
 * @brief represents a format character in a printf call.
 */
typedef enum e_format
{
	FORMAT_NONE,/**< placeholder format, used as error flag or temp value     */
	CHARACTER,  /**< used to display a single ascii charcter                  */
	STRING,     /**< used to display a string                                 */
	POINTER,    /**< used to display a pointer adress                         */
	DECIMAL,    /**< used to display a base 10 decimal number                 */
	INT,        /**< used to display a base 10 integer number                 */
	UINT,       /**< used to display a base 10 unsigned integer number        */
	SMALL_HEX,  /**< used to display a hexadecimal number in small caps       */
	BIG_HEX,    /**< used to display a hexadecimal number in big caps         */
	INDICATOR,  /**< escaped % sign                                           */
	FORMAT_SIZE,/**< number of formats stored in t_e_format                   */
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
	MODIFIER_NONE,/**< placeholder modifier, used as error flag or temp value */
	MODIFIER_SIZE,/**< number of modifiers stored in t_e_modifier             */
}	t_e_modifier;

/**
 * @brief Represents information attached to a modifier, used for comparison
 *        between modifiers and conversion to byte-form representation.
 */
typedef struct s_modinfo
{
	char	modifer;	/**< byte pattern representing the modifier           */
	char	conflics;	/**< byte pattern representing uncompatible modifier  */
}	t_s_modinfo;

short int		ft_formdata(char modgroup, t_e_format format);
char			ft_modify(char modgroup, t_e_modifier modifier);
t_e_modifier	ft_get_modidifier(char c);
bool			ft_ismod(char c);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpadded"
/**
 * @brief Data used by formatter function to display info.
 *
 * @author Eliot McNab
 * @date 12/07/2022
 */
typedef struct s_printdata
{
	short int	formdata; /**< byte form of format and modifier               */
	int			*moddata; /**< values associated to each modifer in [formdata]*/
	va_list		*valist;  /**< variable argument list of values to format     */
	t_s_buffer	*buffer;  /**< buffer used to display format                  */
}	t_s_printdata;
#pragma GCC diagnostic pop

t_s_printdata	*ft_printdata(short int formdata, int *moddata, va_list *valist,
		t_s_buffer *bufer);
void			ft_apply_format(t_s_printdata *printdata);
void			ft_applymod(t_s_printdata *printdata);

#endif
