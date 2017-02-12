/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:32:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/30 18:32:58 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			nblen(intmax_t nb)
{
	int		len;

	len = 2;
	while (nb >= 10 || nb <= -10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int			which_conv_letter(t_struct *core)
{
	if (core->conv_letter == 'd' || core->conv_letter == 'D' ||
		core->conv_letter == 'i' || core->conv_letter == 'u' ||
		core->conv_letter == 'U')
		return (1);
	return (0);
}

int			lu_wcharlen(int c)
{
	if (c < 128)
		return (1);
	else if (c < 2048)
		return (2);
	else if (c < 65536)
		return (3);
	else if (c < 2097152)
		return (4);
	return (0);
}

size_t		lu_wstrlen(wchar_t *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			adjust_size(int i, wchar_t *str)
{
	if (str[i] >= 128 && str[i] < 2048)
		return (1);
	else if (str[i] >= 2048 && str[i] < 65536)
		return (2);
	else if (str[i] >= 65536 && str[i] < 2097152)
		return (3);
	return (0);
}
