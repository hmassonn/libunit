/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:49:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 00:22:51 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "launcher.h"

/*
** Add or comment tests in the following function
*/

int				atoi_launcher(void)
{
	const t_lu_test		loaded_func[] = {
		{"Basic test01", &atoi_basic_test_01},
		{"Basic test02", &atoi_basic_test_02},
		{"Hard	test03", &atoi_hard_test_03},
		{"Hard	test04", &atoi_hard_test_04},
		{NULL, NULL}
	};

	return (lu_launch_tests((t_lu_test*)loaded_func));
}
