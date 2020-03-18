/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:22:54 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/15 16:18:05 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	tab;
	size_t	max;

	if (size == 0)
		return (ft_strlen((char *)src));
	tab = 0;
	max = size;
	size = ft_strlen((char *)src);
	if (max > 0)
	{
		while (src[tab] && tab < max - 1)
		{
			dest[tab] = src[tab];
			tab++;
		}
	}
	dest[tab] = '\0';
	return (size);
}
