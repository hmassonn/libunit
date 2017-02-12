/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_strlen_ok_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 00:02:10 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 18:20:35 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "launcher.h"
#include "lu_libft.h"

int			strlen_basic_test_01(void)
{
	if (lu_strlen("Hello !") == strlen("Hello !"))
		return (0);
	return (-1);
}
