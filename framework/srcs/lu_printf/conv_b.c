/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:53:19 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/30 15:56:20 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			conv_b(t_struct *core)
{
	char		*str;
	int			slen;

	if (!(str = spacing_number(core, 0, 2)))
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
	if (core->hashtag && *str != '0' && *str != '\0' && *str != ' ')
		slen += 2;
	if (core->minus)
		fill_buf_left(core, slen, str, "0b");
	else
		fill_buf_right(core, slen, str, "0b");
	free(str);
	return (0);
}
