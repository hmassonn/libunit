/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:33:26 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/30 11:41:03 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		conv_low_d_left(t_struct *core, int slen, char *str)
{
	if (*str == '-')
		fill_buf_left(core, slen, str + 1, "-");
	else
	{
		if (core->plus)
			fill_buf_left(core, slen + 1, str, "+");
		else
		{
			if (*str != '-' && !core->plus && core->space)
				fill_buf_left(core, slen + 1, str, " ");
			else
				fill_buf_left(core, slen, str, "");
		}
	}
}

void		conv_low_d_right(t_struct *core, int slen, char *str)
{
	if (*str == '-')
		fill_buf_right(core, slen, str + 1, "-");
	else
	{
		if (core->plus)
			fill_buf_right(core, slen + 1, str, "+");
		else
		{
			if (*str != '-' && !core->plus && core->space)
				fill_buf_right(core, slen + 1, str, " ");
			else
				fill_buf_right(core, slen, str, "");
		}
	}
}

int			conv_low_d(t_struct *core)
{
	char		*str;
	int			slen;

	if (!(str = spacing_number(core, 1, 10)))
		return (-1);
	if ((slen = lu_strlen(str)) != -1 && core->pre_on && core->zero)
		core->zero = 0;
	if (*str == '0' && core->precision == 0 && core->pre_on)
	{
		*str = '\0';
		slen--;
	}
	if (*str == '-')
		core->precision = core->precision - slen + 1;
	else
		core->precision = core->precision - slen;
	core->hashtag = 1;
	if (core->precision > 0)
		slen += core->precision;
	if (core->minus)
		conv_low_d_left(core, slen, str);
	else
		conv_low_d_right(core, slen, str);
	free(str);
	return (0);
}
