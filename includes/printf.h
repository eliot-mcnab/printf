/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:27:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 11:40:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "buffer.h"
# include "errors.h"
# include "formdata.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);

#endif
