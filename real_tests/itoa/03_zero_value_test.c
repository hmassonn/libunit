/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_zero_value_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 19:43:29 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/12 19:57:33 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int				itoa_zero_value_test(void)
{
	if ((lu_strcmp(ft_itoa(0), "0")) == 0)
		return (0);
	else
		return (-1);
}
