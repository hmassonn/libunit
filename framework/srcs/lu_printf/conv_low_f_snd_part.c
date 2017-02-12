/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_low_f_snd_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:32:43 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/02 16:28:38 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"
#include <stdio.h>

void	itoa_double(char *str, intmax_t entier, int base, int nb_zero)
{
	const char	*conversion = "0123456789abcdefghijklmnopqrstuvwxyz";
	int			sign;
	int			len;
	intmax_t	nb;

	len = 0;
	while (len++ < nb_zero)
		*str++ = '0';
	nb = entier;
	len = 1;
	while (nb >= base || nb <= -base)
	{
		nb /= base;
		len++;
	}
	str[len] = '\0';
	sign = (entier < 0) ? -1 : 1;
	while (entier >= base || entier <= -base)
	{
		str[--len] = conversion[entier % base * sign];
		entier /= base;
	}
	str[--len] = conversion[entier % base * sign];
}

void	nine_case(char *str)
{
	if (*str != '9')
	{
		if (*str != '.')
			(*str)++;
		else
			nine_case(str - 1);
	}
	else
	{
		*str = '0';
		nine_case(str - 1);
	}
}

void	round_nb(char *str)
{
	if (*str >= '5' && *str <= '9')
	{
		if (*(str - 1) != '9')
		{
			(*(str - 1))++;
		}
		else
		{
			*(str - 1) = '0';
			nine_case(str - 2);
		}
	}
	*str = '\0';
}
