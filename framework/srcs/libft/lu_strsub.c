/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:30:26 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/09 12:07:03 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*lu_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	str = (char *)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		str[i] = s[start + i];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
