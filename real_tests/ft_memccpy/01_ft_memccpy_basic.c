/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_memccpy_basic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:38:34 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:39:55 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

static int		test(char *c, char f, size_t number)
{
	void *dest1;
	void *dest2;
	void *r1;
	void *r2;

	dest1 = malloc(sizeof(char) * number);
	dest2 = malloc(sizeof(char) * number);
	r1 = ft_memccpy(dest1, c, f, number);
	r2 = memccpy(dest2, c, f, number);
	if (r1 - dest1 != r2 - dest2 && r1 != NULL)
		return (-1);
	if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)
			|| (r1 != NULL && strcmp(r1, r2) != 0))
		return (-1);
	if (memcmp(dest1, dest2, number) != 0)
		return (-1);
	return (0);
}

int				ft_memccpy_basic(void)
{
	if (test("test", 'e', sizeof("test")) == -1)
		return (-1);
	if (test("test", 't', sizeof("test")) == -1)
		return (-1);
	if (test("test", 's', sizeof("test")) == -1)
		return (-1);
	if (test("test", '\0', sizeof("test")) == -1)
		return (-1);
	if (test("test", 'q', sizeof("test")) == -1)
		return (-1);
	if (test("", '\0', sizeof("")) == -1)
		return (-1);
	return (0);
}
