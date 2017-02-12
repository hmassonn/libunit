/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_isdigit_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:31:00 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:50:57 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"All", &ft_isdigit_all},
	{NULL, NULL}
};

int		ft_isdigit_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
