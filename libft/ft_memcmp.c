/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:17:33 by mweir             #+#    #+#             */
/*   Updated: 2018/04/23 14:37:14 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char*tng1;
	const unsigned char*tng2;

	tng1 = (const unsigned char *)s1;
	tng2 = (const unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (*tng1 != *tng2)
			return (*tng1 - *tng2);
		if (n)
		{
			tng1++;
			tng2++;
		}
	}
	return (0);
}
