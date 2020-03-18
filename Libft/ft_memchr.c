/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:51:46 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/14 17:44:49 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)s;
	while (n)
	{
		if (s2[i] == (char)c)
			return (s2 + i);
		n--;
		i++;
	}
	return (NULL);
}
