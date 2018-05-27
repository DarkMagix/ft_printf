/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:08:45 by mweir             #+#    #+#             */
/*   Updated: 2018/04/18 13:55:11 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t	i;
	char	*src;

	src = (char*)s;
	i = 0;
	while (i < len)
	{
		if (src[i] == (char)c)
		{
			return (src + i);
		}
		i++;
	}
	return (NULL);
}
