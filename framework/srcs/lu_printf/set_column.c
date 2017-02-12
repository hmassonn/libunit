/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:43:56 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 18:01:21 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			set_column(t_struct *core, char **format)
{
	char	*column;

	(*format) += 3;
	if (**format >= '0' && **format <= '9')
	{
		put_s_buf(core, "\033[");
		while (**format >= '0' && **format <= '9')
		{
			put_c_buf(core, **format);
			(*format)++;
		}
		put_c_buf(core, 'G');
	}
	else
	{
		if (!(column = lu_uintmaxtoa_base(va_arg(core->arg, int), 10)))
			return (-1);
		put_s_buf(core, "\033[");
		put_s_buf(core, column);
		put_c_buf(core, 'G');
		free(column);
	}
	return (0);
}
