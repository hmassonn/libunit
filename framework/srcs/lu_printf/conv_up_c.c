/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_up_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:33:42 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 19:29:34 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		put_unicode(t_struct *core, int c)
{
	if (c < 128 || (c < 256 && core->conv_letter == 'C') ||
		(core->conv_letter == 'c' && core->l == 0))
		put_c_buf(core, c);
	else if (c < 2048)
	{
		put_c_buf(core, ((c >> 6) | 192));
		put_c_buf(core, ((c & 63) | 128));
	}
	else if (c < 65536)
	{
		put_c_buf(core, ((c >> 12) | 224));
		put_c_buf(core, (((c >> 6) & 63) | 128));
		put_c_buf(core, ((c & 63) | 128));
	}
	else if (c < 1114112)
	{
		put_c_buf(core, (c >> 18) | 240);
		put_c_buf(core, (((c >> 12) & 63) | 128));
		put_c_buf(core, (((c >> 6) & 63) | 128));
		put_c_buf(core, ((c & 63) | 128));
	}
}

int			conv_up_c(t_struct *core)
{
	int			c;

	c = va_arg(core->arg, int);
	if (core->minus)
	{
		put_unicode(core, c);
		fill_buf_nchar(core, lu_wcharlen(c), core->width, ' ');
	}
	else
	{
		if (core->zero)
			fill_buf_nchar(core, lu_wcharlen(c), core->width, '0');
		else
			fill_buf_nchar(core, lu_wcharlen(c), core->width, ' ');
		put_unicode(core, c);
	}
	return (0);
}
