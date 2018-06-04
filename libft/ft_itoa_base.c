/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:03:15 by mweir             #+#    #+#             */
/*   Updated: 2018/06/03 19:04:36 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	fill(int nbr)
{
	if (nbr >= 10)
		return ('a' - 10 + nbr);
	else if (nbr < 0)
		return (-nbr + '0');
	else
		return (nbr + '0');
}

static int	get_size(intmax_t nb, int base)
{
	int	size;

	size = 0;
	while (nb >= base)
	{
		nb /= base;
		++size;
	}
	return (size + 1);
}

char	*ft_itoa_base(intmax_t nbr, int base)
{
	char		*res;
	intmax_t	nb;
	intmax_t	index;
	intmax_t	size;

	if (base < 2 || base > 16)
		return (ft_strdup("0"));
	nb = (nbr < 0) ? (-nbr) : nbr;
	size = (int)get_size(nb, base);
	index = 0;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && base == 10 && (res[index] = '-'))
	{
		size++;
	}
	index = size - 1;
	while (nb >= base)
	{
		res[index--] = (char)(nb % base + 48);
		nb /= base;
	}
	res[index] = (char)(nb % base + 48);
	res[size] = '\0';
	return (res);
}
