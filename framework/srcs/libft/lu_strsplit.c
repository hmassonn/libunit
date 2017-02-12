/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:51:40 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/06 20:07:23 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"
#include <string.h>
#include <stdlib.h>

static char			**free_all(char **tabstr, size_t i)
{
	while (i > 0)
	{
		free(tabstr[i]);
		i--;
	}
	free(tabstr);
	return (NULL);
}

static size_t		lu_nb_letters(char const *s, char c)
{
	size_t		nb_letters;

	nb_letters = 0;
	while (*s && *s != c)
	{
		nb_letters++;
		s++;
	}
	return (nb_letters);
}

char				**lu_strsplit(char const *s, char c)
{
	char		**tabstr;
	size_t		nb_words;
	size_t		i;

	nb_words = lu_nb_words(s, c);
	if (!(tabstr = (char **)malloc(sizeof(*tabstr) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (i < nb_words)
	{
		while (*s == c)
			s++;
		if (!(tabstr[i] = lu_strsub(s, 0, lu_nb_letters(s, c))))
			return (free_all(tabstr, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	tabstr[nb_words] = 0;
	return (tabstr);
}
