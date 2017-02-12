/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 11:40:55 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 19:20:01 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

int		put_sign(char *str, int nb, long double d)
{
	int		i;

	i = 0;
	if (d < 0 && d > -1)
	{
		while (str[i + 2] && str[i + 2] == '0')
			i++;
		if (i == 0 && str[2] == '1')
			i++;
	}
	else
	{
		while (str[i + 1] && str[i + 1] == '0')
			i++;
	}
	if (nb < 0 || d < 0)
		str[i] = '-';
	else if (nb != 0 || (nb == 0 && str[i + 1] == '1'))
		i++;
	return (i);
}

void	remove_zero(t_struct *core, char *str)
{
	*str = '\0';
	if ((core->conv_letter == 'g' || core->conv_letter == 'G')
		&& core->precision > 0 && core->hashtag == 0)
	{
		while (*(str - 1) == '0')
			str--;
		if (*(str - 1) == '.')
			str--;
		*str = '\0';
	}
	else if (core->precision <= 0 && core->hashtag == 1)
	{
		while (*str)
			str++;
		*str++ = '.';
		*str = '\0';
	}
}

void	fill_str(t_struct *core, long double decimal, char *str)
{
	int		i;
	int		entier;
	int		neg;

	neg = 1;
	if (core->precision > 0)
		*str++ = '.';
	i = 0;
	if (decimal <= 1 && decimal >= -1)
	{
		while (i < core->precision + 1)
		{
			decimal *= 10;
			entier = (int)decimal;
			if (entier < 0)
				neg = -1;
			itoa_double(str, entier * neg, 10, 0);
			decimal -= entier;
			i++;
			str++;
		}
		round_nb(str - 1);
		remove_zero(core, str - 1);
	}
}

int		conv_low_f(t_struct *core)
{
	long double		d;
	intmax_t		entier;
	int				len;
	char			*str;

	if (core->pre_on == 0)
		core->precision = 6;
	core->pre_on = 1;
	set_modifier_double(core, &d);
	entier = (intmax_t)d;
	len = core->precision == 0 ? nblen(entier) : nblen(entier) + 1;
	if (!(str = (char *)malloc(sizeof(char) * (len + core->precision + 3 + 1))))
		return (-1);
	itoa_double(str, entier, 10, 2);
	len = (core->precision > 0) ? len - 1 : len;
	fill_str(core, d - entier, str + len + 1);
	len = put_sign(str, entier, d);
	update_plus_and_space(core, d);
	if (core->minus)
		fill_buf_lelu_double(core, lu_strlen(str + len), str + len);
	else
		fill_buf_right_double(core, lu_strlen(str + len), str + len);
	free(str);
	return (0);
}
