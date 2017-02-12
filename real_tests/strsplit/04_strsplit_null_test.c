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

int			strsplit_null_test_04(void)
{
	int		i;
	char	**ft_tab;
	char	**tab;

	i = 0;
	ft_tab = ft_strsplit(NULL, ' ');
	tab = lu_strsplit(NULL, ' ');
	if (tab == ft_tab)
		return (0);
	return (-1);
}
