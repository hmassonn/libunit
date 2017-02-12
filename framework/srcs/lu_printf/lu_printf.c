/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:01:38 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/03 14:51:10 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			work_on_format(t_struct *core, char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (manage_arg(core, &format) == -1)
				return (-1);
		}
		else
		{
			put_c_buf(core, *format);
			format++;
		}
	}
	if (core->i)
		print_buffer(core);
	return (0);
}

int			lu_printf(const char *format, ...)
{
	t_struct	core;

	init_struct(&core);
	va_start(core.arg, format);
	va_copy(core.arg_cp, core.arg);
	if (work_on_format(&core, (char *)format) == -1)
		core.len = -1;
	va_end(core.arg_cp);
	va_end(core.arg);
	return (core.len);
}
