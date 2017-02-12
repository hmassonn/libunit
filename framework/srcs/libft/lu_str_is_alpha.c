/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:42:08 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/04 15:42:09 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"

int		lu_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!lu_isalpha(*str))
			return (0);
		str++;
	}
	return (1);
}
