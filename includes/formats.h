/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:53:33 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/02 10:59:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H
# define FORMATS_H

typedef enum e_format
{
	CHARACTER, /* used to display a single ascii charcter                     */ 
	STRING,    /* used to display a string                                    */ 
	POINTER,   /* used to display a pointer adress                            */ 
	DECIMAL,   /* used to display a base 10 decimal number                    */ 
	INT,       /* used to display a base 10 integer number                    */ 
	UINT,      /* used to display a base 10 unsigned integer number           */ 
	SMALL_HEX, /* used to display a hexadecimal number in small caps          */ 
	BIG_HEX    /* used to display a hexadecimal number in big caps            */ 
}	t_format;

#endif
