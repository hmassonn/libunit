/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:30:51 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/09 12:14:40 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"
#include <stdlib.h>

char	*lu_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * (lu_strlen(s1) + lu_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	str = lu_strcpy(str, (char *)s1);
	str = lu_strcat(str, (char *)s2);
	return (str);
}
