/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacing_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:57:56 by jtoty             #+#    #+#             */
/*   Updated: 2017/01/18 18:34:31 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_printf.h"

char			*set_coma(int slen, int nb_space, char *str, int separator)
{
	char		*str_coma;
	int			slen_space;
	int			i;

	slen_space = slen + nb_space;
	if (!(str_coma = (char *)malloc(sizeof(char) * (slen_space + 1))))
		return (NULL);
	str_coma[slen_space] = '\0';
	i = 0;
	while (slen_space > 0)
	{
		if (nb_space > 0 && i == separator)
		{
			str_coma[--slen_space] = ',';
			nb_space--;
			i = -1;
		}
		else
			str_coma[--slen_space] = str[--slen];
		i++;
	}
	free(str);
	return (str_coma);
}

char			*set_space(int slen, int nb_space, char *str, int separator)
{
	char		*str_space;
	int			slen_space;
	int			i;

	slen_space = slen + nb_space;
	if (!(str_space = (char *)malloc(sizeof(char) * (slen_space + 1))))
		return (NULL);
	str_space[slen_space] = '\0';
	i = 0;
	while (slen_space > 0)
	{
		if (nb_space > 0 && i == separator)
		{
			str_space[--slen_space] = ' ';
			nb_space--;
			i = -1;
		}
		else
			str_space[--slen_space] = str[--slen];
		i++;
	}
	free(str);
	return (str_space);
}

char			*ucount_space(t_struct *core, int *nb_space, int base, int sep)
{
	char			*str;

	if (!(str = lu_uintmaxtoa_base(set_modifier(core), base)))
		return (NULL);
	*nb_space = (lu_strlen(str) - 1) / sep;
	return (str);
}

char			*count_space(t_struct *core, int *nb_space, int base, int sep)
{
	intmax_t		nb;
	char			*str;

	nb = set_modifier(core);
	if (!(str = lu_intmaxtoa_base(nb, base)))
		return (NULL);
	if (nb < 0)
		*nb_space = (lu_strlen(str) - 2) / sep;
	else
		*nb_space = (lu_strlen(str) - 1) / sep;
	return (str);
}

char			*spacing_number(t_struct *core, int signed_nb, int base)
{
	char		*str;
	int			nb_space;
	int			separator;

	if (core->quote)
	{
		separator = core->conv_letter == 'b' ? 4 : 3;
		if (signed_nb)
		{
			if (!(str = count_space(core, &nb_space, base, separator)))
				return (NULL);
		}
		else
		{
			if (!(str = ucount_space(core, &nb_space, base, separator)))
				return (NULL);
		}
		if (which_conv_letter(core))
			return (set_coma(lu_strlen(str), nb_space, str, separator));
		return (set_space(lu_strlen(str), nb_space, str, separator));
	}
	else if (signed_nb)
		return (lu_intmaxtoa_base(set_modifier(core), base));
	else
		return (lu_uintmaxtoa_base(set_modifier(core), base));
}
