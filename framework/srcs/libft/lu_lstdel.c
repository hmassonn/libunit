/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:25:49 by jtoty             #+#    #+#             */
/*   Updated: 2016/12/16 12:28:28 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"
#include <stdlib.h>

void	lu_lstdel(t_listo **alst, void (*del)(void *, size_t))
{
	t_listo		*tmp;

	tmp = *alst;
	while (tmp)
	{
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp->next;
	}
	*alst = NULL;
}
