/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 10:22:20 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/07 19:58:20 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		lu_atoi(const char *str)
{
	int result;
	int negative;

	result = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + negative * (*str - '0');
		str++;
	}
	return (result);
}
