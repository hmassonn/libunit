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

int			strdup_basic_test_01(void)
{
	if (!lu_strcmp(ft_strdup("lorem ipsum"), strdup("lorem ipsum")))
		return (0);
	return (-1);
}
