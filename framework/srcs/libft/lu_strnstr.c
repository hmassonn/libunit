/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:44:14 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/09 11:58:56 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*lu_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	const char		*substr;

	if (!(*little))
		return ((char *)big);
	while (*big && len > 0)
	{
		i = 0;
		if (*big == little[i])
		{
			substr = big;
			while (little[i] && *(big + i) == little[i] && (len - i) > 0)
				i++;
			if (!little[i])
				return ((char *)substr);
		}
		len--;
		big++;
	}
	return (NULL);
}
