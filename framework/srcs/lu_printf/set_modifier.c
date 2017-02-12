/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 13:56:01 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/01 18:29:12 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

uintmax_t		signed_modifier(t_struct *core)
{
	if (core->h)
		return ((short)va_arg(core->arg, int));
	else if (core->hh)
		return ((char)va_arg(core->arg, int));
	else if (core->l)
		return (va_arg(core->arg, long int));
	else if (core->ll)
		return (va_arg(core->arg, long long int));
	else if (core->j)
		return (va_arg(core->arg, intmax_t));
	else if (core->z)
		return (va_arg(core->arg, long int));
	else
		return (va_arg(core->arg, int));
}

uintmax_t		unsigned_modifier(t_struct *core)
{
	if (core->h)
		return ((unsigned short)va_arg(core->arg, int));
	else if (core->hh)
		return ((unsigned char)va_arg(core->arg, int));
	else if (core->l)
		return (va_arg(core->arg, unsigned long int));
	else if (core->ll)
		return (va_arg(core->arg, unsigned long long int));
	else if (core->j)
		return (va_arg(core->arg, uintmax_t));
	else if (core->z)
		return (va_arg(core->arg, size_t));
	else
		return (va_arg(core->arg, unsigned int));
}

uintmax_t		set_modifier(t_struct *core)
{
	if (core->conv_letter == 'd' || core->conv_letter == 'i' ||
		core->conv_letter == 'D')
		return (signed_modifier(core));
	else
		return (unsigned_modifier(core));
}

void			set_modifier_double(t_struct *core, long double *d)
{
	if (core->upl)
		*d = va_arg(core->arg, long double);
	else
		*d = va_arg(core->arg, double);
}
