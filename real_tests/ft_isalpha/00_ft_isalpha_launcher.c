/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_isalpha_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:24:54 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:25:23 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"All", &ft_isalpha_all_test},
	{NULL, NULL}
};

int		ft_isalpha_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
