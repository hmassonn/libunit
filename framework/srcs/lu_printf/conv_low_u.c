/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:37:02 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/29 19:54:24 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			conv_low_u(t_struct *core)
{
	char		*str;
	int			slen;

	if (!(str = spacing_number(core, 0, 10)))
		return (-1);
	slen = lu_strlen(str);
	if (core->pre_on && core->zero)
		core->zero = 0;
	if (core->pre_on && !core->precision && *str == '0' && !core->width)
		*str = '\0';
	else if (core->pre_on && !core->precision && *str == '0' && core->width)
		*str = ' ';
	core->precision -= slen;
	if (core->precision > 0)
		slen += core->precision;
	if (core->minus)
		fill_buf_left(core, slen, str, "");
	else
		fill_buf_right(core, slen, str, "");
	free(str);
	return (0);
}
