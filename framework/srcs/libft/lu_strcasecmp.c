/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:45:59 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/20 17:09:40 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"

int			lu_strcasecmp(const char *s1, const char *s2)
{
	while (*s1 &&
		(unsigned char)lu_tolower(*s1) == (unsigned char)lu_tolower(*s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)lu_tolower(*s1) -
			(unsigned char)lu_tolower(*s2));
}
