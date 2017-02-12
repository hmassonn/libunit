/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:43:14 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/29 12:08:23 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			conv_p(t_struct *core)
{
	char		*str;
	int			slen;

	if (!(str = lu_uintmaxtoa_base(va_arg(core->arg, uintmax_t), 16)))
		return (-1);
	slen = lu_strlen(str);
	if (core->pre_on && core->zero)
		core->zero = 0;
	if (core->pre_on && !core->precision && *str == '0')
	{
		*str = '\0';
		slen--;
	}
	core->precision -= slen;
	if (core->precision > 0)
		slen += core->precision;
	core->hashtag = 1;
	slen += 2;
	if (core->minus)
		fill_buf_left(core, slen, str, "0x");
	else
		fill_buf_right(core, slen, str, "0x");
	free(str);
	return (0);
}
