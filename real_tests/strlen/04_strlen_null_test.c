/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_strlen_buse_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 00:02:28 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 00:02:29 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "launcher.h"

int			strlen_null_test_04(void)
{
	if (ft_strlen(NULL) == strlen(NULL))
		return (0);
	return (-1);
}
