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

int				putchar_launcher(void)
{
	const t_lu_test		loaded_func[] = {
		{"Basic test01", &putchar_basic_test_01},
		{NULL, NULL}
	};

	return (lu_launch_tests((t_lu_test*)loaded_func));
}
