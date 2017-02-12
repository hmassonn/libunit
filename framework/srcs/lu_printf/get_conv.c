/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:34:04 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/25 14:44:02 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			conv_bracket(t_struct *core, char **format)
{
	(*format)++;
	if (lu_strncmp(*format, "fd", 2) == 0)
		core->fd = va_arg(core->arg, int);
	else if (lu_strncmp(*format, "col", 3) == 0)
	{
		if (set_column(core, format) == -1)
			return (-1);
	}
	else
		set_colors(core, format);
	while (*format && **format != '}')
		(*format)++;
	(*format)++;
	return (0);
}

int			get_conv(t_struct *core, char **format)
{
	const char		*conv = "\%sSpdDioOuUxXcCbnfFeEgGaA{";
	int				i;

	i = 0;
	while (**format && conv[i] && **format != conv[i])
	{
		i++;
		if (!conv[i])
		{
			i = 0;
			(*format)++;
		}
	}
	if (**format)
	{
		if (**format == '{')
			return (conv_bracket(core, format));
		else
		{
			core->conv_letter = conv[i];
			(*format)++;
			return (core->func_ptr[i](core));
		}
	}
	return (-1);
}
