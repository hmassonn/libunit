/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:27:06 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/08 12:00:53 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"
#include <stdlib.h>

void	*lu_memalloc(size_t size)
{
	void *mem;

	mem = malloc(sizeof(*mem) * size);
	if (!mem)
		return (NULL);
	lu_bzero(mem, size);
	return (mem);
}
