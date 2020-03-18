/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:26:27 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/17 15:02:02 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len(long int n)
{
	int		res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char				*ft_itoa(int n)
{
	char		*res;
	long long	nb;
	int			idx;

	nb = n;
	idx = ft_len(nb);
	res = (char *)malloc((idx + 1) * sizeof(char));
	if (res == 0)
		return (0);
	res[idx] = '\0';
	idx = idx - 1;
	if (nb == 0)
		res[idx] = 48;
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		res[idx] = (nb % 10) + 48;
		nb = nb / 10;
		idx--;
	}
	return (res);
}
