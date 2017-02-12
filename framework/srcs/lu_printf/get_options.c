/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:17:19 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/30 13:03:07 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

void		update_option(char *option, char **format, char c)
{
	*option = 1;
	while (**format == c)
		(*format)++;
}

void		get_options(t_struct *core, char **format)
{
	while (**format == '-' || **format == '+' || **format == '#' ||
		**format == ' ' || **format == '0' || **format == '\'')
	{
		if (**format == '-')
			update_option(&core->minus, format, '-');
		if (**format == '+')
			update_option(&core->plus, format, '+');
		if (**format == '#')
			update_option(&core->hashtag, format, '#');
		if (**format == ' ')
			update_option(&core->space, format, ' ');
		if (**format == '0')
			update_option(&core->zero, format, '0');
		if (**format == '\'')
			update_option(&core->quote, format, '\'');
	}
}
