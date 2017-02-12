/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:43:13 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/19 19:05:24 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "lu_libft.h"

char	*lu_strndup(const char *s1, size_t n)
{
	char		*strdup;
	size_t		len;

	len = lu_strlen(s1);
	if (len > n)
		len = n;
	strdup = (char *)malloc(sizeof(*strdup) * len + 1);
	if (!strdup)
		return (NULL);
	lu_strncpy(strdup, s1, len);
	strdup[len] = '\0';
	return (strdup);
}
