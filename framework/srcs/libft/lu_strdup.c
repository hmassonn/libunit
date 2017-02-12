/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:43:56 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 10:54:01 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "lu_libft.h"

char	*lu_strdup(const char *s1)
{
	char	*strdup;

	strdup = (char *)malloc(sizeof(*strdup) * lu_strlen(s1) + 1);
	if (!strdup)
		return (NULL);
	lu_strcpy(strdup, s1);
	return (strdup);
}
