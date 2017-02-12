/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 10:33:56 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/30 10:35:09 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		fill_buf_nchar(t_struct *core, int start, int end, char c)
{
	while (start < end)
	{
		put_c_buf(core, c);
		start++;
	}
}

void		fill_buf_left(t_struct *core, int slen, char *str, char *htag)
{
	if ((core->hashtag && *str != '0' && *str != '\0' && *str != ' ') ||
		core->conv_letter == 'p' || core->conv_letter == 'd' ||
		core->conv_letter == 'D' || core->conv_letter == 'i')
		put_s_buf(core, htag);
	fill_buf_nchar(core, 0, core->precision, '0');
	put_s_buf(core, str);
	fill_buf_nchar(core, slen, core->width, ' ');
}

void		fill_buf_right(t_struct *core, int slen, char *str, char *htag)
{
	if (core->zero)
	{
		if ((core->hashtag && *str != '0' && *str != '\0' && *str != ' ') ||
			core->conv_letter == 'p' || core->conv_letter == 'd' ||
			core->conv_letter == 'D' || core->conv_letter == 'i')
			put_s_buf(core, htag);
		fill_buf_nchar(core, slen, core->width, '0');
	}
	else
	{
		fill_buf_nchar(core, slen, core->width, ' ');
		if ((core->hashtag && *str != '0' && *str != '\0' && *str != ' ') ||
		core->conv_letter == 'p' || core->conv_letter == 'd' ||
		core->conv_letter == 'D' || core->conv_letter == 'i')
			put_s_buf(core, htag);
	}
	fill_buf_nchar(core, 0, core->precision, '0');
	put_s_buf(core, str);
}
