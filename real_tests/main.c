/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:39:54 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:47:13 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"
#include "libunit.h"

/*
**	const t_lu_test		all_func[] = {
**		{"Strlen", &strlen_launcher},
**		{"Atoi", &atoi_launcher},
**		// for comment a routine
**		{"strdup", &strdup_launcher},
**		{"strsplit", &strsplit_launcher},
**		{NULL, NULL}
**	};
*/

int			main(void)
{
	int					func_ok;
	int					i;
	const t_lu_test		all_func[] = {
		{"STRLEN", &strlen_launcher},
		{"ATOI", &atoi_launcher},
		{"STRDUP", &strdup_launcher},
		{"STRSPLIT", &strsplit_launcher},
		{"FT_BZERO", &ft_bzero_launcher},
		{"FT_ISALNUM", &ft_isalnum_launcher},
		{"FT_ISALPHA", &ft_isalpha_launcher},
		{"FT_ISASCII", &ft_isascii_launcher},
		{"FT_ISDIGIT", &ft_isdigit_launcher},
		{"FT_ISPRINT", &ft_isprint_launcher},
		{"FT_MEMALLOC", &ft_memalloc_launcher},
		{"FT_MEMCCPY", &ft_memccpy_launcher},
		{"ITOA", &itoa_launcher},
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
