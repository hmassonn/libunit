/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:26:46 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 19:05:59 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"
#include <stdlib.h>

t_listo	*lu_lstnew(void const *content, size_t content_size)
{
	t_listo	*elem;

	elem = (t_listo *)malloc(sizeof(t_listo));
	if (!elem)
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = lu_memalloc(content_size)))
			return (NULL);
		elem->content = lu_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
