/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:46:43 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/25 16:26:48 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		get_modifier_bis(t_struct *core, char **format)
{
	if (**format == 'j' && (*format)++)
		core->j = 1;
	else if (**format == 'z' && (*format)++)
		core->z = 1;
	else if (**format == 'L' && (*format)++)
		core->upl = 1;
}

void		get_modifier(t_struct *core, char **format)
{
	if (**format == 'h')
	{
		if (*(++*format) == 'h')
		{
			(*format)++;
			core->hh = 1;
		}
		else
			core->h = 1;
	}
	else if (**format == 'l')
	{
		if (*(++*format) == 'l')
		{
			(*format)++;
			core->ll = 1;
		}
		else
			core->l = 1;
	}
	else
		get_modifier_bis(core, format);
}
