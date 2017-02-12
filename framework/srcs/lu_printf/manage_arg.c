/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:34:19 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 18:01:34 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			manage_arg_dollar(t_struct *core, char **format)
{
	init_var(core);
	init_modifier(core);
	*format = core->format_cp;
	get_arg_conv(core, format);
	get_modifier(core, format);
	get_n_arg(core, core->arg_conv);
	return (get_conv(core, format));
}

int			manage_arg(t_struct *core, char **format)
{
	(*format)++;
	core->format_cp = *format;
	if (core->dollar == 0)
	{
		init_var(core);
		init_modifier(core);
		get_options(core, format);
		if (get_width(core, format) == 0)
		{
			get_precision(core, format);
			get_modifier(core, format);
			return (get_conv(core, format));
		}
		else
			return (manage_arg_dollar(core, format));
	}
	else
		return (manage_arg_dollar(core, format));
	return (0);
}
