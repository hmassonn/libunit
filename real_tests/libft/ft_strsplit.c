/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:54:25 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:46:58 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static char		**filling(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i + k] && s[i + k] != c)
		{
			tab[j][k] = s[i + k];
			k++;
		}
		if (s[i])
			tab[j][k] = '\0';
		i += k;
		if (s[i])
			j++;
		k = 0;
	}
	return (tab);
}

static char		**malloc_string(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i + k] && s[i + k] != c)
			k++;
		if (s[i])
		{
			if ((tab[j] = (char *)malloc(sizeof(char) * k + 1)) == NULL)
				return (NULL);
		}
		i += k;
		if (s[i])
			j++;
		k = 0;
	}
	tab = filling(s, c, tab);
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	j = count_word(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * j + 1)) == NULL)
		return (NULL);
	tab[j] = NULL;
	if (j > 0)
		tab = malloc_string(s, c, tab);
	return (tab);
}
