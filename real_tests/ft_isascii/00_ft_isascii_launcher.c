/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_isascii_launcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:27:23 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:27:46 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static const struct s_lu_test g_test[] = {
	{"All", &ft_isascii_all},
	{NULL, NULL}
};

int		ft_isascii_launcher(void)
{
	return (lu_launch_tests((struct s_lu_test*)g_test));
}
