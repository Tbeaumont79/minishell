/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:19:16 by apitoise          #+#    #+#             */
/*   Updated: 2019/10/08 12:19:18 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrchr(const char *str, int c)
{
	int	rev;
	int	save;

	rev = 0;
	save = 0;
	while (str[rev] != '\0')
		rev++;
	while (str[rev] != (char)c)
	{
		if (str[rev] == str[0] && (char)c != str[0])
			return (0);
		rev--;
	}
	while (save < rev)
	{
		str++;
		save++;
	}
	return ((char *)str);
}
