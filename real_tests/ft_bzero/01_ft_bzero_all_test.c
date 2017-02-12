/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_bzero_all_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:15:05 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:26:08 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static int	test(char *c, size_t number)
{
	char	*t1;
	char	*t2;
	int		ret;

	ret = 0;
	t1 = strdup(c);
	t2 = strdup(c);
	bzero((void*)t1, number);
	ft_bzero((void*)t2, number);
	if (memcmp(t1, t2, number) != 0)
		ret = -1;
	free(t1);
	free(t2);
	return (ret);
}

int			ft_bzero_all_test(void)
{
	if (test("almost every programmer should know memset !!!", 6) == -1)
		return (-1);
	if (test("almost every programmer should know memset !!!", 6) == -1)
		return (-1);
	if (test("almost every programmer should know memset !!!", 0) == -1)
		return (-1);
	if (test("almost every programmer should know memset !!!",
				sizeof("almost every programmer should know memset !!!"
					)) == -1)
		return (-1);
	if (test("a", sizeof("a")) == -1)
		return (-1);
	if (test("agjhdskgl", sizeof("a")) == -1)
		return (-1);
	return (0);
}
