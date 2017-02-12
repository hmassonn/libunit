/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:54:08 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 11:55:41 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lu_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (unsigned char)*s1 == (unsigned char)*s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
