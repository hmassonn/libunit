/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:49:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 15:27:08 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "launcher.h"

/*
** Add or comment tests in the following function
*/

int				strlen_launcher(void)
{
	const t_lu_test		loaded_func[] = {
		{"Basic	test01", &strlen_basic_test_01},
		{"KO	test03", &strlen_ko_test_02},
		{"SEGV	test02", &strlen_segv_test_03},
		{"BUSE	test04", &strlen_buse_test_04},
		{"Time	test05", &strlen_timeout_test_05},
		{NULL, NULL}
	};

	return (lu_launch_tests((t_lu_test*)loaded_func));
}
