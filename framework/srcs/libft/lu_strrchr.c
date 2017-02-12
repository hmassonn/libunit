/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:27:16 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 11:31:42 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*lu_strrchr(char *s, int c)
{
	char	*last_oc;

	last_oc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_oc = s;
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (last_oc);
}
