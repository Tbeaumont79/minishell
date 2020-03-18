/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:05:34 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/17 14:42:12 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				neg;
	int				pos;

	pos = 0;
	while (str[pos] == '\t' || str[pos] == '\n' || str[pos] == '\v'
			|| str[pos] == '\f' || str[pos] == '\r' || str[pos] == ' ')
		pos++;
	neg = 1;
	if (str[pos] == '+' || str[pos] == '-')
	{
		if (str[pos] == '-')
			neg++;
		pos++;
	}
	res = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		res = res * 10;
		res = res + str[pos] - 48;
		pos++;
	}
	if (neg % 2 == 0)
		return (-res);
	return (res);
}
