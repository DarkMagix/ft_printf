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

char	fill(int nbr, int base)
{
	if (nbr >= base)
		return ('a' - base + nbr);
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

char	*ft_itoa_base(long long int nbr, int base)
{
	char			*res;
	long long int	nb;
	long long int	index;
	long long int	size;
	char			*hex = "0123456789abcdef";

	if (base < 2 || base > 16)
		return (ft_strdup("0"));
	nb = (nbr < 0) ? (-nbr) : nbr;
	size = (int)get_size(nb, base);
	index = 0;
	if (!(res = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0 ? 1 : 0)))))
		return (0);
	if (nbr < 0 && base == 10 && (res[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= base)
	{
		res[index--] = hex[nb % base];
		nb /= base;
	}
	res[index] = hex[nb % base];
	res[size] = '\0';
	return (res);
}
