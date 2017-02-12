/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_launch_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:28:27 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 17:39:06 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "lu_printf.h"

char			*catch_signal(int signal)
{
	if (signal == 6)
		return ("ABRT");
	if (signal == 10)
		return ("BUSE");
	if (signal == 11)
		return ("SEGV");
	if (signal == 14)
		return ("TIMEOUT");
	return ("UNKNOWN_ERROR");
}

char			*lu_exec_test(int (*unit_test)(void), int *tests_ok)
{
	pid_t			father;
	int				ret;

	ret = 0;
	if ((father = fork()) == -1)
		return ("FORK ERROR");
	if (father > 0)
	{
		wait(&father);
		if (WIFSIGNALED(father))
			return (catch_signal(WTERMSIG(father)));
		else if (father == 0)
		{
			(*tests_ok)++;
			return ("OK");
		}
	}
	if (father == 0)
	{
		ualarm(5000000, 0);
		exit((*unit_test)());
	}
	return ("KO");
}

int				lu_launch_tests(t_lu_test loaded_func[])
{
	int				i;
	int				tests_ok;
	char			*str;

	i = 0;
	tests_ok = 0;
	while (loaded_func[i].unit_test)
	{
		lu_printf("\t> %s :", loaded_func[i].name);
		str = lu_exec_test(loaded_func[i].unit_test, &tests_ok);
		if (*str == 'O')
			lu_printf("%{col30}[%{green}%s%{!}]\n", str);
		else
			lu_printf("%{col30}[%{red}%s%{!}]\n", str);
		i++;
	}
	lu_printf("\n%{yellow}%d/%d tests checked%{!}\n", tests_ok, i);
	if (tests_ok != i)
		return (-1);
	return (0);
}
