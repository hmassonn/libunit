/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:33:38 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/02 10:33:42 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"

size_t		lu_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (size > 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	if (size)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}
