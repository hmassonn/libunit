/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strlen_segv_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 00:02:21 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 00:02:22 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "launcher.h"

int			strlen_hard_test_03(void)
{
	if (ft_strlen("\n\n\f\r\t") == strlen("\n\n\f\r\t"))
		return (0);
	return (-1);
}
