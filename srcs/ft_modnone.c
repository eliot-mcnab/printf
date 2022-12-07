/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modnone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:03:17 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/07 14:05:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/formatters.h"

ssize_t	ft_modnone(t_s_printdata *printdata)
{
	ft_buffadd_str(printdata->buffer, TBA_MOD);
}
