/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:49:17 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/16 12:29:21 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*lu_itoa(int n)
{
	unsigned int	len;
	int				n_bis;
	int				abs;
	char			*str;

	n_bis = n;
	len = (n >= 0) ? 1 : 2;
	while (n_bis >= 10 || n_bis <= -10)
	{
		n_bis /= 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	str[len] = '\0';
	str[0] = '-';
	abs = (n < 0) ? -1 : 1;
	while (n >= 10 || n <= -10)
	{
		str[len - 1] = n % 10 * abs + '0';
		len--;
		n /= 10;
	}
	str[len - 1] = n % 10 * abs + '0';
	return (str);
}
