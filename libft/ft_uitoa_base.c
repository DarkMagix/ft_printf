/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:00:42 by mweir             #+#    #+#             */
/*   Updated: 2018/06/03 19:04:50 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	u_fill(int nbr, int size)
{
	if (nbr < 0 && !size)
	{
		size++;
		return ('-');
	}
	if (nbr >= 10)
		return ('a' - 10 + nbr);
	else if (nbr < 0)
		return (-nbr + '0');
	else
		return (nbr + '0');
}

int		u_numsize(uintmax_t nbr, int base)
{
	int size;

	size = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

char	*ft_uitoa_base(uintmax_t nbr, int base)
{
	char		*res;
	int			j;
	static int	size;
	size = 0;
	j = u_numsize(nbr, base) - 1;
	res = ft_memalloc(j + 3);
	if (!nbr)
		res[0] = '0';
	while (nbr)
	{
		res[j] = u_fill(nbr % base, size);
		nbr /= base;
		j--;
	}
	return (res);
}
