/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:39:54 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 18:53:43 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"
#include "libunit.h"

int			main(void)
{
	int					func_ok;
	int					i;
	const t_lu_test		all_func[] = {
		{"STRLEN", &strlen_launcher},
		{NULL, NULL}
	};

	lu_printf("%{green}*********************************\n");
	lu_printf("****%{col10}42 - Unit Tests%{col30}****\n");
	lu_printf("*********************************%{!}\n");
	i = 0;
	func_ok = 0;
	while (all_func[i].unit_test)
	{
		lu_printf("%{*_blue}%s:%{!}\n", all_func[i].name);
		if (all_func[i].unit_test() == 0)
			func_ok++;
		i++;
	}
	if (func_ok == i)
		lu_printf("%{green}%d/%d functions checked%{!}\n", func_ok, i);
	else
		lu_printf("%{red}%d/%d functions checked%{!}\n", func_ok, i);
	return (0);
}
