/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_a_thd_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 20:00:49 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/01 21:41:37 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

int			get_exp_a_long(long double *d)
{
	int				exp;

	exp = 0;
	if (*d >= 8 || *d <= -8)
	{
		while (*d >= 16 || *d <= -16)
		{
			exp++;
			*d /= 2;
		}
		return (exp);
	}
	else
	{
		while ((*d > 0 && *d < 8) || (*d < 0 && *d > -8))
		{
			exp++;
			*d *= 2;
		}
		return (-exp);
	}
}
