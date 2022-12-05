/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:10:53 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 16:18:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "buffer.h"
# include "formdata.h"
# include "formatters.h"

# define FORM_INDICATOR '%'

ssize_t	ft_parse(const char *str, va_list valist);

#endif
