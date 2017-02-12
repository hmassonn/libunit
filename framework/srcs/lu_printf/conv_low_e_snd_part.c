/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_e_snd_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:40:24 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/09 20:38:57 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

void	update_exp(char *str, char *start, int *exp)
{
	if (str == start)
	{
		if (*exp < 0)
			(*exp)--;
		else
			(*exp)++;
	}
}

void	nine_case_e(char *str, int *exp, char *start)
{
	if (*str != '9')
	{
		if (*str != '.')
			(*str)++;
		else
			nine_case_e(str - 1, exp, start);
	}
	else
	{
		*str = '0';
		update_exp(str - 1, start, exp);
		nine_case_e(str - 1, exp, start);
	}
}

void	round_number_e(t_struct *core, char *str, int *exp, char *start)
{
	int		i;

	i = 0;
	while (*str && *str == '0')
		str++;
	start = str - 1;
	str++;
	while (i++ < core->precision && *str)
	{
		if (*str == '.')
			i--;
		str++;
	}
	if (*str >= '5' && *str <= '9')
	{
		if (*(str - 1) != '9')
			(*(str - 1))++;
		else
		{
			*(str - 1) = '0';
			update_exp(str - 2, start, exp);
			nine_case_e(str - 2, exp, start);
		}
	}
	remove_zero_e(core, str);
}

void	set_exp_zero(t_struct *core, char *str)
{
	int		i;

	i = 0;
	if (core->precision > 0 || core->hashtag)
	{
		while (*str && *str == '0')
			str++;
		str++;
		while (i < core->precision)
		{
			str++;
			i++;
		}
	}
	else
		str++;
	if (core->conv_letter == 'e' || core->conv_letter == 'g')
		*str = 'e';
	else if (core->conv_letter == 'E' || core->conv_letter == 'G')
		*str = 'E';
	str++;
	*str++ = '+';
	*str++ = '0';
	*str++ = '0';
	*str = '\0';
}

void	set_exp(t_struct *core, char *str, int exp)
{
	int		i;

	i = 0;
	while (*str && (*str == '0' || *str == '-'))
		str++;
	str++;
	if (*str == '.')
		str++;
	while (i++ < core->precision && *str)
		str++;
	if (core->conv_letter == 'e' || core->conv_letter == 'g')
		*str++ = 'e';
	else if (core->conv_letter == 'E' || core->conv_letter == 'G')
		*str++ = 'E';
	if (exp < 0)
	{
		exp *= -1;
		*str = '-';
	}
	else
		*str = '+';
	str++;
	*str++ = '0' + exp / 10;
	*str++ = '0' + exp % 10;
	*str = '\0';
}
