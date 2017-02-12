/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:42:03 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/09 10:42:06 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"

t_listo	*lu_lstmap(t_listo *lst, t_listo *(*f)(t_listo *elem))
{
	t_listo	*tmp;
	t_listo	*elem;
	t_listo	*begin;

	elem = NULL;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!elem)
		{
			if (!(elem = lu_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			begin = elem;
		}
		else
		{
			if (!(elem->next = lu_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			elem = elem->next;
		}
		lst = lst->next;
	}
	return (begin);
}
