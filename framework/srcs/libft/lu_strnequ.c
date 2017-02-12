/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:35:29 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/21 14:53:17 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "lu_libft.h"

int		lu_strnequ(char const *s1, char const *s2, size_t n)
{
	if (lu_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
