/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:02:09 by mweir             #+#    #+#             */
/*   Updated: 2018/04/19 20:10:58 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int value, int pow)
{
	int result;

	if (pow < 0)
		return (0);
	result = 1;
	if (pow < 0)
		return (0);
	while (pow > 0)
	{
		result *= value;
		pow--;
	}
	return (result);
}
