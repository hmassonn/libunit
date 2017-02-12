/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_memalloc_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:38:16 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:38:18 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "launcher.h"

int		ft_memalloc_basic(void)
{
	int		i;
	char	*str;

	str = ft_memalloc(5);
	i = 0;
	while (i < 5)
		str[i++] = 5;
	free(str);
	i = 0;
	str = ft_memalloc(5);
	if (str[0] == 0 && str[1] == 0 &&
			str[2] == 0 && str[3] == 0 && str[4] == 0)
		return (0);
	return (-1);
}
