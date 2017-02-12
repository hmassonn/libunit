/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:42:39 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/03 14:48:12 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		print_buffer(t_struct *core)
{
	write(core->fd, core->buffer, core->i);
	core->len += core->i;
	core->i = 0;
}

void		put_c_buf(t_struct *core, unsigned char c)
{
	core->buffer[core->i] = c;
	core->i++;
	if (core->i == BUFER_SIZ)
		print_buffer(core);
}

void		put_s_buf(t_struct *core, char *str)
{
	while (*str)
	{
		put_c_buf(core, *str);
		str++;
	}
}
