/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:44:43 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 17:42:09 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		low_s_left(t_struct *core, int slen, char *str)
{
	int		i;

	if (core->pre_on == 0)
		core->precision = slen;
	i = 0;
	while (i < slen && i < core->precision)
	{
		put_c_buf(core, str[i]);
		i++;
	}
	fill_buf_nchar(core, 0, core->width - i, ' ');
}

void		low_s_right(t_struct *core, int slen, char *str)
{
	int		i;

	if (core->pre_on == 0)
		core->precision = slen;
	i = 0;
	while (i < slen && i < core->precision)
		i++;
	if (core->zero)
		fill_buf_nchar(core, 0, core->width - i, '0');
	else
		fill_buf_nchar(core, 0, core->width - i, ' ');
	i = 0;
	while (i < slen && i < core->precision)
	{
		put_c_buf(core, str[i]);
		i++;
	}
}

int			conv_low_s(t_struct *core)
{
	char	*str;

	if (core->l)
		return (conv_up_s(core));
	else
	{
		str = va_arg(core->arg, char *);
		if (!str)
			str = "(null)";
		if (core->minus)
			low_s_left(core, lu_strlen(str), str);
		else
			low_s_right(core, lu_strlen(str), str);
		return (0);
	}
}
