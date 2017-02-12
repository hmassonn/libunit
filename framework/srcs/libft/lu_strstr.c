/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:32:07 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 13:25:43 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*lu_strstr(const char *big, const char *little)
{
	size_t			i;
	const char		*substr;

	if (!(*little))
		return ((char *)big);
	while (*big)
	{
		i = 0;
		if (*big == little[i])
		{
			substr = big;
			while (little[i] && *(big + i) == little[i])
				i++;
			if (!little[i])
				return ((char *)substr);
		}
		big++;
	}
	return (NULL);
}
