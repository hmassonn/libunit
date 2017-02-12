/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:38:55 by jtoty             #+#    #+#             */
/*   Updated: 2016/11/04 15:41:45 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lu_libft.h"

void	lu_putnbr_fd(int n, int fd)
{
	if (n >= 0)
	{
		if (n >= 10)
			lu_putnbr_fd(n / 10, fd);
		lu_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		lu_putchar_fd('-', fd);
		if (n <= -10)
			lu_putnbr_fd(n / -10, fd);
		lu_putchar_fd(n % -10 * -1 + '0', fd);
	}
}
