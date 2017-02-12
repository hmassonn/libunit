/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:28:24 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 17:37:26 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		get_precision(t_struct *core, char **format)
{
	if (**format == '.')
	{
		(*format)++;
		core->pre_on = 1;
		if (**format == '*')
		{
			core->precision = va_arg(core->arg, int);
			if (core->precision < 0)
			{
				core->pre_on = 0;
				core->precision = 0;
			}
			(*format)++;
		}
		else
		{
			core->precision = lu_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
	}
}
