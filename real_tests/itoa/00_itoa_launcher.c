/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_itoa_launcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:40:20 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:55:10 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int				itoa_launcher(void)
{
	const t_lu_test		testlist[] = {
		{"Basic test", &itoa_basic_test},
		{"Int min", &itoa_int_min_test},
		{"Zero test", &itoa_zero_value_test},
		{NULL, NULL}
	};

	return (lu_launch_tests((t_lu_test*)testlist));
}
