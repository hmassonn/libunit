/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:18:17 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:26:34 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"All", &ft_isalnum_all_test},
	{NULL, NULL}
};

int		ft_isalnum_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
