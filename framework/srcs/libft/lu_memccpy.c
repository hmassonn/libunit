/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:31:31 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 10:46:33 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*lu_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		(*(unsigned char *)dst) = (*(unsigned char *)src);
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst + 1);
		n--;
		dst++;
		src++;
	}
	return (NULL);
}
