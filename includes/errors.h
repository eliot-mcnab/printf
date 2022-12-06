/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:50:39 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 11:06:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file errors.h
 * @brief Holds error codes for use throughout ft_printf
 * @author Eliot McNab
 * @date 12/05/2022
 */

#ifndef ERRORS_H
# define ERRORS_H

# define NO_ERROR      0
# define WRITE_ERROR  -1
# define FORMAT_ERROR -2
# define READ_ERROR   -3
# define PARSE_ERROR  -9
# define MALLOC_ERROR -10
# define NULL_ERROR   -11
# define ARG_ERROR    -12

#endif
