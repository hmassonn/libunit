/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 11:03:57 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/30 10:32:17 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			conv_low_o(t_struct *core)
{
	char		*str;
	int			slen;

	if (!(str = spacing_number(core, 0, 8)))
		return (-1);
	if ((slen = lu_strlen(str)) != -1 && core->pre_on && core->zero)
		core->zero = 0;
	if (core->hashtag && *str != '0')
		slen++;
	if (*str == '0' && core->pre_on && !core->precision && !core->hashtag)
	{
		if (core->width)
			*str = ' ';
		else
			*str = '\0';
	}
	core->precision -= slen;
	if (core->precision > 0)
		slen += core->precision;
	if (core->minus)
		fill_buf_left(core, slen, str, "0");
	else
		fill_buf_right(core, slen, str, "0");
	free(str);
	return (0);
}
