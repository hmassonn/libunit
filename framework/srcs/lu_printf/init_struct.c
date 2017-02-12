/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:41:51 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/01 21:59:11 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		init_func_ptr(t_struct *core)
{
	core->func_ptr[0] = &conv_percent;
	core->func_ptr[1] = &conv_low_s;
	core->func_ptr[2] = &conv_up_s;
	core->func_ptr[3] = &conv_p;
	core->func_ptr[4] = &conv_low_d;
	core->func_ptr[5] = &conv_up_d;
	core->func_ptr[6] = &conv_i;
	core->func_ptr[7] = &conv_low_o;
	core->func_ptr[8] = &conv_up_o;
	core->func_ptr[9] = &conv_low_u;
	core->func_ptr[10] = &conv_up_u;
	core->func_ptr[11] = &conv_low_x;
	core->func_ptr[12] = &conv_up_x;
	core->func_ptr[13] = &conv_low_c;
	core->func_ptr[14] = &conv_up_c;
	core->func_ptr[15] = &conv_b;
	core->func_ptr[16] = &conv_n;
	core->func_ptr[17] = &conv_low_f;
	core->func_ptr[18] = &conv_up_f;
	core->func_ptr[19] = &conv_low_e;
	core->func_ptr[20] = &conv_up_e;
	core->func_ptr[21] = &conv_low_g;
	core->func_ptr[22] = &conv_up_g;
	core->func_ptr[23] = &conv_low_a;
	core->func_ptr[24] = &conv_up_a;
}

void		init_modifier(t_struct *core)
{
	core->h = 0;
	core->hh = 0;
	core->l = 0;
	core->ll = 0;
	core->j = 0;
	core->z = 0;
	core->upl = 0;
}

void		init_var(t_struct *core)
{
	core->hashtag = 0;
	core->zero = 0;
	core->minus = 0;
	core->plus = 0;
	core->space = 0;
	core->quote = 0;
	core->width = 0;
	core->precision = -1;
	core->pre_on = 0;
	core->conv_letter = 0;
}

void		init_struct(t_struct *core)
{
	core->i = 0;
	core->len = 0;
	core->dollar = 0;
	core->fd = 1;
	init_func_ptr(core);
}
