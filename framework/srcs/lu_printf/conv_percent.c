/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:49:11 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/30 12:22:33 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

int			conv_percent(t_struct *core)
{
	if (core->minus)
	{
		put_c_buf(core, '%');
		fill_buf_nchar(core, 1, core->width, ' ');
	}
	else
	{
		if (core->zero)
			fill_buf_nchar(core, 1, core->width, '0');
		else
			fill_buf_nchar(core, 1, core->width, ' ');
		put_c_buf(core, '%');
	}
	return (0);
}
