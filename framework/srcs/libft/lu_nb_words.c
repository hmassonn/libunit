/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_nb_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:02:57 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/06 20:03:00 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		lu_nb_words(char const *s, char c)
{
	size_t		nb_words;

	nb_words = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			nb_words++;
		while (*s && *s != c)
			s++;
	}
	return (nb_words);
}
