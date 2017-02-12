/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:40:08 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/09 14:25:19 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		lu_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (size - i > 0 && dst[i])
		i++;
	size -= i;
	while (size > 1 && src[j])
	{
		dst[i + j] = src[j];
		j++;
		size--;
	}
	if (j > 0)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
