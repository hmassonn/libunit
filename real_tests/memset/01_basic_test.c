/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:52:18 by jlereffa          #+#    #+#             */
/*   Updated: 2017/02/12 18:01:50 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"
#include "string.h"

int	memset_basic_test(void)
{
	unsigned char	ft_dst[10];
	unsigned char	dst[10];

	ft_memset(ft_dst, 0, 10);
	memset(dst, 0, 10);
	if ((memcmp(ft_dst, dst, 10) == 0))
		return (0);
	else
		return (-1);
}
