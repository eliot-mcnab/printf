/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:59:50 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 19:57:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"
#include <stdio.h>

int	main(void)
{
	char	*test;
	int		error;

	test = "";
	error = ft_printf("%\n", test);
	ft_putnbr_fd(error, STDOUT);
	return (0);
}
