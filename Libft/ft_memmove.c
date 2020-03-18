/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:47:25 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/14 17:32:14 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (len == 0)
		return (dst);
	if (source > dest)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
	return (dst);
}
