/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:15:18 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:26:00 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"basic", &bzero_basic},
	{"All", &ft_bzero_all_test},
	{NULL, NULL}
};

int		ft_bzero_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
