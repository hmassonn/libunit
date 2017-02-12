/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:13:31 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/20 19:03:32 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>

char	*lu_uintmaxtoa_base(uintmax_t value, unsigned char base)
{
	short				len;
	uintmax_t			nb;
	char				*str;
	const char			*conversion = "0123456789abcdefghijklmnopqrstuvxyz";

	if (base < 2 || base > 36)
		return (NULL);
	nb = value;
	len = 1;
	while (nb >= base)
	{
		nb /= base;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (value >= base)
	{
		str[--len] = conversion[value % base];
		value /= base;
	}
	str[len - 1] = conversion[value % base];
	return (str);
}
