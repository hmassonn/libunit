/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_e_thd_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:12:24 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 21:31:12 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

/*
** else if (core->precision <= 0 && core->hashtag == 1)
** {
**		while (*str)
**			str++;
**		*str++ = '.';
**		*str = '\0';
** }
*/

void	remove_zero_e(t_struct *core, char *str)
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
}

void	remove_dot_e(t_struct *core, char *str)
{
	(void)core;
	while (*str)
		str++;
	if (*(str - 1) == '.')
		*(str - 1) = '\0';
}

void	set_dot_sign_exp2(t_struct *core, char *str, int *i)
{
	if (core->precision > 0 || core->hashtag)
	{
		while (str[*i] && str[*i] == '0')
			(*i)++;
		str[*i - 1] = str[*i];
		if (str[*i + 1] != '\0')
			str[*i] = '.';
		else if (core->conv_letter == 'e' || core->conv_letter == 'E')
			str[*i] = '.';
		else if (core->hashtag)
			str[*i] = '.';
		else
			str[*i] = '\0';
	}
}
