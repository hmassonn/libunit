/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_memalloc_launcher.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:37:45 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:51:17 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"basic", &ft_memalloc_basic},
	{NULL, NULL}
};

int		ft_memalloc_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
