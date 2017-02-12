/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_int_min_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:43:06 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:56:45 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include "libunit.h"

int				itoa_int_min_test(void)
{
	char		*str;
	int			result;

	str = ft_itoa(INT_MIN);
	result = lu_strcmp(str, "-2147483648");
	free(str);
	if (result == 0)
		return (0);
	else
		return (-1);
}
