/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_a_snd_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:35:39 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 18:44:41 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

int			get_exp_a(long double *d)
{
	int				exp;

	exp = 0;
	if (*d >= 2 || *d <= -2)
	{
		while (*d >= 2 || *d <= -2)
		{
			exp++;
			*d /= 2;
		}
		return (exp);
	}
	else
	{
		while ((*d > 0 && *d < 1) || (*d < 0 && *d > -1))
		{
			exp++;
			*d *= 2;
		}
		return (-exp);
	}
}

void		nine_case_a(char *str, int *exp)
{
	if (*str == 'x' && *(str + 1) == '0')
	{
		*(str + 1) = '1';
		(*exp) += 4;
	}
	else
	{
		if (*str != 'f')
		{
			if (*str != '.')
			{
				if (*str == '9')
					*str = 'a';
				else
					(*str)++;
			}
			else
				nine_case_a(str - 1, exp);
		}
		else
		{
			*str = '0';
			nine_case_a(str - 1, exp);
		}
	}
}

void		round_number_a(char *str, int *exp)
{
	if (*str == '9' || (*str >= 'a' && *str <= 'f'))
	{
		if (*(str - 1) != 'f')
		{
			if (*(str - 1) == '9')
				(*(str - 1)) = 'a';
			else if (*(str - 1) == '.')
			{
				if (*(str - 2) == 'f' && (*(str - 2) = '1') == '1')
					*exp += 4;
				else if (*(str - 2) == '9')
					*(str - 2) = 'a';
				else
					(*(str - 2))++;
			}
			else
				(*(str - 1))++;
		}
		else
		{
			*(str - 1) = '0';
			nine_case_a(str - 2, exp);
		}
	}
}
