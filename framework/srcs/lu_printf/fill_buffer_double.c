/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:41:32 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 19:20:02 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

void	update_plus_and_space(t_struct *core, long double d)
{
	if (d < 0)
	{
		core->plus = 0;
		core->space = 0;
	}
	else if (core->plus)
		core->space = 0;
	core->precision = 0;
}

void	fill_buf_right_double2(t_struct *core, int slen, char *str)
{
	fill_buf_nchar(core, slen, core->width, ' ');
	if (*str == '-')
	{
		put_c_buf(core, '-');
		put_s_buf(core, str + 1);
	}
	else
	{
		if (core->plus)
			put_c_buf(core, '+');
		else if (core->space)
			put_c_buf(core, ' ');
		put_s_buf(core, str);
	}
}

void	fill_buf_right_double(t_struct *core, int slen, char *str)
{
	if (core->plus || core->space)
		slen++;
	if (core->zero)
	{
		if (*str == '-')
		{
			put_c_buf(core, '-');
			fill_buf_nchar(core, slen, core->width, '0');
			put_s_buf(core, str + 1);
		}
		else
		{
			if (core->plus)
				put_c_buf(core, '+');
			else if (core->space)
				put_c_buf(core, ' ');
			fill_buf_nchar(core, slen, core->width, '0');
			put_s_buf(core, str);
		}
	}
	else
		fill_buf_right_double2(core, slen, str);
}

void	fill_buf_lelu_double(t_struct *core, int slen, char *str)
{
	if (core->space)
	{
		put_c_buf(core, ' ');
		slen++;
	}
	else if (core->plus)
	{
		put_c_buf(core, '+');
		slen++;
	}
	put_s_buf(core, str);
	fill_buf_nchar(core, slen, core->width, ' ');
}
