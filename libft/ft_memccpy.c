/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:31:24 by mweir             #+#    #+#             */
/*   Updated: 2018/04/18 13:54:34 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;
	
	i = 0;
	d = dest;
	s = src;
	while (i < len)
	{
		d[i] = s[i];
		if (s[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
