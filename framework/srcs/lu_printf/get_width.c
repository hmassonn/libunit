/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:00:50 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 18:01:04 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int		get_width(t_struct *core, char **format)
{
	if (**format != '*')
	{
		core->width = lu_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
		if (**format == '$')
		{
			core->dollar = 1;
			return (1);
		}
	}
	else
	{
		core->width = va_arg(core->arg, int);
		if (core->width < 0)
		{
			if (core->width == -2147483648)
				core->width = core->width + 1;
			core->width *= -1;
			core->minus = 1;
		}
		(*format)++;
	}
	return (0);
}
