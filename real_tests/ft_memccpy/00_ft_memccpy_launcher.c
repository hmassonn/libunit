/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_memccpy_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:39:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:51:26 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"All", &ft_memccpy_basic},
	{NULL, NULL}
};

int		ft_memccpy_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
