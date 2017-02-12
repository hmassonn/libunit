/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:13:31 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/16 12:30:53 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*lu_itoa_base(int value, int base)
{
	short		len;
	int			nb;
	char		*str;
	const char	*conversion = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (base < 2 || base > 36 || (nb = value) != value)
		return (NULL);
	len = (value < 0 && base == 10) ? 2 : 1;
	while (nb >= base || nb <= -base)
	{
		nb /= base;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[0] = '-';
	str[len] = '\0';
	nb = (value < 0) ? -1 : 1;
	while (value >= base || value <= -base)
	{
		str[--len] = conversion[value % base * nb];
		value /= base;
	}
	str[len - 1] = conversion[value % base * nb];
	return (str);
}
