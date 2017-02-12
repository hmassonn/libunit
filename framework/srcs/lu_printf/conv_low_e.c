/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:38:13 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 21:15:15 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

void	fill_e_str(t_struct *core, long double decimal, char *str)
{
	int		i;
	int		entier;
	int		neg;

	neg = 1;
	i = 0;
	if (decimal <= 1 && decimal >= -1)
	{
		while (i < core->precision + 1)
		{
			decimal *= 10;
			entier = (int)decimal;
			if (entier < 0)
				neg = -1;
			itoa_double(str, entier * neg, 10, 0);
			decimal -= entier;
			i++;
			str++;
		}
	}
}

void	set_dot_sign_exp(t_struct *core, char *str, long double nb, int exp)
{
	int		i;

	i = 0;
	if (nb != 0)
		set_dot_sign_exp2(core, str, &i);
	else if (core->precision > 0 || core->hashtag)
		str[i + 1] = '.';
	if ((i = 0) == 0 && nb < 0)
	{
		while (str[i + 1] == '0')
			i++;
		str[i] = '-';
	}
	if (nb != 0)
		set_exp(core, str, exp);
	else
		set_exp_zero(core, str);
}

int		get_exp(long double *nb)
{
	int				exp;
	long double		number;

	exp = 0;
	if (*nb >= 10 || *nb <= -10)
	{
		number = *nb;
		while (number >= 10 || number <= -10)
		{
			exp++;
			number /= 10;
		}
		return (exp);
	}
	else
	{
		while ((*nb > 0 && *nb < 1) || (*nb < 0 && *nb > -1))
		{
			exp++;
			*nb *= 10;
		}
		return (-exp);
	}
}

void	conv_low_e2(t_struct *core, char *str, long double d)
{
	int		len;

	len = 0;
	if (d != 0)
		while (str[len] && str[len] == '0')
			len++;
	update_plus_and_space(core, d);
	if (core->minus)
		fill_buf_lelu_double(core, lu_strlen(str + len), str + len);
	else
		fill_buf_right_double(core, lu_strlen(str + len), str + len);
}

int		conv_low_e(t_struct *core)
{
	long double		d;
	intmax_t		entier;
	int				len;
	char			*str;
	int				exp;

	if (core->pre_on == 0)
		core->precision = 6;
	core->pre_on = 1;
	set_modifier_double(core, &d);
	exp = get_exp(&d);
	entier = (intmax_t)d;
	len = core->precision == 0 ? nblen(entier) : nblen(entier) + 1;
	if (!(str = (char *)malloc(sizeof(char) *
		(len + core->precision + 5 + 2))))
		return (-1);
	itoa_double(str, entier, 10, 3);
	len = core->precision > 0 ? len - 1 : len;
	fill_e_str(core, d - entier, str + len + 2);
	round_number_e(core, str, &exp, str);
	set_dot_sign_exp(core, str, d, exp);
	conv_low_e2(core, str, d);
	free(str);
	return (0);
}
