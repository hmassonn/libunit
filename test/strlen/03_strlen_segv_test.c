/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_strlen_segv_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 00:02:21 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 18:09:45 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "lu_libft.h"

int			strlen_segv_test_03(void)
{
	if (lu_strlen(NULL) == strlen("Hello"))
		return (0);
	return (-1);
}
