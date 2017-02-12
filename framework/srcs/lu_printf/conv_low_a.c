/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:10:45 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 19:01:11 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

int			set_fst_part(t_struct *core, char *str, long double d,
						long double d_cp)
{
	int			i;

	i = 0;
	if (d_cp != 0)
	{
		if (d_cp < 0)
			str[i++] = '-';
		lu_strcpy(str + i, "0x");
		if (core->upl)
			itoa_double(str + i + 2, (intmax_t)d, 16, 0);
		else
			str[i + 2] = '1';
		i += 3;
	}
	else
	{
		lu_strcpy(str, "0x0");
		i += 3;
	}
	if (core->precision > 0 || core->hashtag)
		str[i++] = '.';
	return (i);
}

void		set_third_part(t_struct *core, char *str, int exp, int i)
{
	while (i < core->precision && core->pre_on == 1)
	{
		str[i] = '0';
		i++;
	}
	str[i++] = 'p';
	if (exp < 0)
	{
		exp *= -1;
		str[i++] = '-';
	}
	else
		str[i++] = '+';
	if (exp < 10)
		str[i++] = '0' + exp % 10;
	else
	{
		str[i++] = '0' + exp / 10;
		str[i++] = '0' + exp % 10;
	}
	str[i] = '\0';
}

void		set_snd_part(t_struct *core, long double d, char *str, int *exp)
{
	int				i;
	intmax_t		entier;
	const char		*base = "0123456789abcdef";
	int				neg;

	i = 0;
	entier = (intmax_t)d;
	neg = 1;
	if (entier < 0)
		neg = -1;
	d -= entier;
	while (i < core->precision && d != 0)
	{
		d *= 16;
		entier = (intmax_t)d;
		str[i] = base[entier * neg];
		d -= entier;
		i++;
	}
	d *= 16;
	entier = (intmax_t)d;
	str[i] = base[entier * neg];
	if (core->pre_on)
		round_number_a(str + i, exp);
	set_third_part(core, str, *exp, i);
}

void		remove_dot(t_struct *core, char *str, long double d)
{
	int		i;

	if (core->hashtag == 0)
	{
		i = 0;
		while (str[i + 1] && str[i + 1] != 'p')
			i++;
		if (str[i] == '.')
		{
			while (str[i])
			{
				str[i] = str[i + 1];
				i++;
			}
		}
	}
	if (core->conv_letter == 'A')
		lu_strupcase(str);
	update_plus_and_space(core, d);
}

/*
**while (*(str + 1) && *(str + 1) != 'p')
**	str++;
**if (*str == '.')
**{
**	while (*str)
**	{
**		*str = *(str + 1);
**		str++;
**	}
**}
*/
/*
** malloc
** 1 pour le signe
** 4 pour 0x1.
** 13 pour la longueur max apres le '.'
** 4 pour p+e15
** 1 pour '\0'
*/

int			conv_low_a(t_struct *core)
{
	long double		d;
	long double		d_cp;
	int				exp;
	char			*str;
	int				i;

	if (core->pre_on == 0)
		core->precision = 13;
	set_modifier_double(core, &d);
	d_cp = d;
	if (!(str = (char *)malloc(sizeof(char) * (23 + core->precision))))
		return (-1);
	if (core->upl)
		exp = get_exp_a_long(&d);
	else
		exp = get_exp_a(&d);
	i = set_fst_part(core, str, d, d_cp);
	set_snd_part(core, d, str + i, &exp);
	remove_dot(core, str, d_cp);
	if (core->minus)
		fill_buf_lelu_double(core, lu_strlen(str), str);
	else
		fill_buf_right_double(core, lu_strlen(str), str);
	free(str);
	return (0);
}
