/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:32:12 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/02 10:32:14 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"

char	*lu_strcapitalize(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && !lu_isalnum(str[i]))
			i++;
		if (str[i])
		{
			if (lu_islower(str[i]))
				str[i] = lu_toupper(str[i]);
			i++;
		}
		while (str[i] && lu_isalnum(str[i]))
		{
			if (lu_isupper(str[i]))
				str[i] = lu_tolower(str[i]);
			i++;
		}
	}
	return (str);
}
