/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:10:53 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/08 11:13:31 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file parse.h
 * @brief Holds parsing constants used in ft_parse
 * @author Eliot McNab
 * @date 12/06/2022
 */

#ifndef PARSE_H
# define PARSE_H

# include "buffer.h"
# include "formdata.h"
# include "formatters.h"

/**
 * Indicates the start of a format specifier in a format string passed as
 * arugment to ft_printf(const char *, ...)
 */
# define FORM_INDICATOR '%'

ssize_t	ft_parse(const char *str, va_list *valist);

#endif
