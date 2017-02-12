/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_strlen_buse_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 00:02:28 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 20:38:14 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libunit.h"

int			strlen_buse_test_04(void)
{
	const char	*str = "Aello !";

	*str = 'H';
	if (lu_strlen(str) == strlen("Hello !"))
		return (0);
	return (-1);
}
