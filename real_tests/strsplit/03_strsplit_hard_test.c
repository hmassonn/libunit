/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_strlen_ok_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 00:02:10 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 00:02:11 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "launcher.h"

int			strsplit_hard_test_03(void)
{
	int		i;
	char	**ft_tab;
	char	**tab;

	ft_tab = ft_strsplit("   ipsum dolor sit amet,   ", ' ');
	tab = lu_strsplit("   ipsum dolor sit amet,   ", ' ');
	i = 0;
	while (ft_tab[i])
	{
		if (ft_strcmp(tab[i], ft_tab[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}
