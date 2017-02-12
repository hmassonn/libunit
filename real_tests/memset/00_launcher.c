/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:10:58 by jlereffa          #+#    #+#             */
/*   Updated: 2017/02/12 18:08:46 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "launcher.h"

int				memset_launcher(void)
{
	const t_unit_test	testlist[] = {
		{"Basic test", &memset_basic_test},
		{NULL, NULL}
	};

	return (launch_tests((t_unit_test*)testlist));
}
