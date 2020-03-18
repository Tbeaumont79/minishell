/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:23:18 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/17 12:34:08 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*new;
	unsigned char		*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	new = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (n == 0)
		return (dst);
	while (n)
	{
		*new = *source;
		new++;
		source++;
		n--;
	}
	return (dst);
}
