/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_up_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:06:11 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/29 11:40:25 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		up_s_left(t_struct *core, int strlen, wchar_t *str)
{
	int		i;

	i = 0;
	while (i < strlen)
	{
		put_unicode(core, str[i]);
		if (str[i] >= 128 && str[i] < 2048)
			core->width -= 1;
		else if (str[i] >= 2048 && str[i] < 65536)
			core->width -= 2;
		else if (str[i] >= 65536 && str[i] < 2097152)
			core->width -= 3;
		i++;
	}
	fill_buf_nchar(core, 0, core->width - i, ' ');
}

void		up_s_lelu_l(t_struct *core, int strlen, wchar_t *str)
{
	int		i;
	int		adjuster;

	i = 0;
	while (i < strlen && i < core->precision)
	{
		adjuster = adjust_size(i, str);
		core->precision -= adjuster;
		if (i < core->precision)
		{
			put_unicode(core, str[i]);
			core->width -= adjuster;
			i++;
		}
	}
	fill_buf_nchar(core, 0, core->width - i, ' ');
}

void		up_s_right(t_struct *core, int strlen, wchar_t *str)
{
	int		i;

	i = 0;
	while (i < strlen)
	{
		if (str[i] >= 128 && str[i] < 2048)
			core->width -= 1;
		else if (str[i] >= 2048 && str[i] < 65536)
			core->width -= 2;
		else if (str[i] >= 65536 && str[i] < 2097152)
			core->width -= 3;
		i++;
	}
	if (core->zero)
		fill_buf_nchar(core, 0, core->width - i, '0');
	else
		fill_buf_nchar(core, 0, core->width - i, ' ');
	i = 0;
	while (i < strlen)
	{
		put_unicode(core, str[i]);
		i++;
	}
}

void		up_s_right_l(t_struct *core, int strlen, wchar_t *str)
{
	int		i;
	int		adjuster;
	int		cp_precision;

	i = 0;
	cp_precision = core->precision;
	while (i < strlen && i < core->precision)
	{
		adjuster = adjust_size(i, str);
		core->precision -= adjuster;
		if (i < core->precision && ++i)
			core->width -= adjuster;
	}
	if (core->zero)
		fill_buf_nchar(core, 0, core->width - i, '0');
	else
		fill_buf_nchar(core, 0, core->width - i, ' ');
	i = 0;
	while (i < strlen && i < cp_precision)
	{
		adjuster = adjust_size(i, str);
		cp_precision -= adjuster;
		i < cp_precision ? put_unicode(core, str[i++]) : 1;
	}
}

int			conv_up_s(t_struct *core)
{
	wchar_t		*str;

	str = va_arg(core->arg, wchar_t *);
	if (!str)
		str = L"(null)";
	if (core->pre_on)
	{
		if (core->minus)
			up_s_lelu_l(core, lu_wstrlen(str), str);
		else
			up_s_right_l(core, lu_wstrlen(str), str);
	}
	else
	{
		if (core->minus)
			up_s_left(core, lu_wstrlen(str), str);
		else
			up_s_right(core, lu_wstrlen(str), str);
	}
	return (0);
}
