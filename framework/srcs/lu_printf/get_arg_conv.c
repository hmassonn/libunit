/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:58:12 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 18:59:36 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		get_n_arg(t_struct *core, int nb_arg)
{
	while (nb_arg > 1)
	{
		va_arg(core->arg, int);
		nb_arg--;
	}
}

void		get_abs_width(t_struct *core)
{
	core->width = va_arg(core->arg, int);
	if (core->width < 0)
	{
		if (core->width == -2147483648)
			core->width = core->width + 1;
		core->width *= -1;
		core->minus = 1;
	}
}

void		get_arg_conv(t_struct *core, char **format)
{
	core->arg_conv = lu_atoi(*format);
	*core->arg = *core->arg_cp;
	while ((**format >= '0' && **format <= '9') || **format == '$')
		(*format)++;
	get_options(core, format);
	if (**format == '*' && (*format)++)
	{
		get_n_arg(core, lu_atoi(*format));
		while ((**format >= '0' && **format <= '9') || **format == '$')
			(*format)++;
		get_abs_width(core);
		*core->arg = *core->arg_cp;
	}
	if (**format == '.' && (*format)++)
	{
		if ((core->pre_on = 1) == 1 && **format == '*')
		{
			(*format)++;
			get_n_arg(core, lu_atoi(*format));
			while ((**format >= '0' && **format <= '9') || **format == '$')
				(*format)++;
			core->precision = va_arg(core->arg, int);
			*core->arg = *core->arg_cp;
		}
	}
}
