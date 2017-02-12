/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_up_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:22:13 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/20 20:05:07 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			conv_up_x(t_struct *core)
{
	char		*str;
	int			slen;

	if (!(str = spacing_number(core, 0, 16)))
		return (-1);
	slen = lu_strlen(str);
	if (core->pre_on && core->zero)
		core->zero = 0;
	if (core->pre_on && core->precision == 0 && *str == '0' && !core->width)
		*str = '\0';
	else if (core->pre_on && core->precision == 0 && *str == '0' && core->width)
		*str = ' ';
	core->precision -= slen;
	if (core->precision > 0)
		slen += core->precision;
	if (core->hashtag && *str != '0' && *str != '\0' && *str != ' ')
		slen += 2;
	if (core->minus)
		fill_buf_left(core, slen, lu_strupcase(str), "0X");
	else
		fill_buf_right(core, slen, lu_strupcase(str), "0X");
	free(str);
	return (0);
}
