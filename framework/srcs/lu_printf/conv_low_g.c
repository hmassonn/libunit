/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_g.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:41:30 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 18:42:19 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int		get_exp_g(long double d, int *zero)
{
	int				exp;

	exp = 0;
	*zero = 0;
	if (d >= 10 || d <= -10)
	{
		while (d >= 10 || d <= -10)
		{
			exp++;
			d /= 10;
		}
		return (exp);
	}
	else
	{
		while ((d > 0 && d < 1) || (d < 0 && d > -1))
		{
			exp++;
			d *= 10;
			(*zero)++;
		}
		return (-exp);
	}
}

int		conv_low_g(t_struct *core)
{
	long double		d;
	va_list			arg_cpy;
	int				exp;
	int				len;
	int				zero;

	if (core->pre_on == 0)
		core->precision = 6;
	else if (core->precision == 0)
		core->precision = 1;
	core->pre_on = 1;
	va_copy(arg_cpy, core->arg);
	set_modifier_double(core, &d);
	*core->arg = *arg_cpy;
	va_end(arg_cpy);
	exp = get_exp_g(d, &zero);
	len = nblen((intmax_t)d) - 1;
	if (exp < -4 || exp >= core->precision)
	{
		core->precision--;
		return (conv_low_e(core));
	}
	core->precision = core->precision - len + zero;
	return (conv_low_f(core));
}
