/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_isprint_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:35:21 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:35:43 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"All", &ft_isprint_all},
	{NULL, NULL}
};

int		ft_isprint_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
