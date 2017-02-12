/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:34:37 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 13:25:53 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"
#include <string.h>
#include <stdlib.h>

char	*lu_strtrim(char const *s)
{
	size_t		l;
	size_t		l_bis;
	char		*str;

	l = lu_strlen(s);
	l_bis = l;
	while (l > 0 && (s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t'))
		l--;
	if (l)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
		{
			l--;
			s++;
		}
	}
	if (l_bis == l)
		return (lu_strdup(s));
	str = lu_strnew(l);
	if (!str)
		return (NULL);
	str = lu_strncpy(str, s, l);
	return (str);
}
