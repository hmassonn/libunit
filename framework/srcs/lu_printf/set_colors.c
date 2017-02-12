/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:58:33 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 17:59:44 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		change_background(t_struct *core, char **format)
{
	if (**format == 's')
	{
		(*format)++;
		if (**format == 'b')
		{
			if (lu_strnstr(*format, "bla", 3) && (*format)++)
				put_s_buf(core, "\033[40m");
			else if ((*format)++)
				put_s_buf(core, "\033[44m");
		}
		else if (**format == 'c' && (*format)++)
			put_s_buf(core, "\033[46m");
		else if (**format == 'g' && (*format)++)
			put_s_buf(core, "\033[42m");
		else if (**format == 'p' && (*format)++)
			put_s_buf(core, "\033[45m");
		else if (**format == 'r' && (*format)++)
			put_s_buf(core, "\033[41m");
		else if (**format == 'w' && (*format)++)
			put_s_buf(core, "\033[47m");
		else if (**format == 'y' && (*format)++)
			put_s_buf(core, "\033[43m");
	}
}

void		change_font(t_struct *core, char **format)
{
	while (**format == '_' || **format == '*' ||
			**format == '!' || **format == ' ')
	{
		if (**format == '_')
			put_s_buf(core, "\033[4m");
		if (**format == '*')
			put_s_buf(core, "\033[1m");
		if (**format == '!')
			put_s_buf(core, "\033[0m");
		if (**format == ' ')
			put_s_buf(core, "\033[H\033[2J");
		(*format)++;
	}
}

void		set_colors(t_struct *core, char **format)
{
	change_font(core, format);
	change_background(core, format);
	if (**format == 'b')
	{
		if (lu_strnstr(*format, "bla", 3))
			put_s_buf(core, "\033[30m");
		else
			put_s_buf(core, "\033[34m");
	}
	else if (**format == 'c')
		put_s_buf(core, "\033[36m");
	else if (**format == 'g')
		put_s_buf(core, "\033[32m");
	else if (**format == 'p')
		put_s_buf(core, "\033[35m");
	else if (**format == 'r')
		put_s_buf(core, "\033[31m");
	else if (**format == 'w')
		put_s_buf(core, "\033[37m");
	else if (**format == 'y')
		put_s_buf(core, "\033[33m");
}
