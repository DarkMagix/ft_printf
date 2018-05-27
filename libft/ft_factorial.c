/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:16:47 by mweir             #+#    #+#             */
/*   Updated: 2018/04/20 14:18:18 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_factorial(int value)
{
	int i;
	int fact_nbr;

	if (value > 12)
		return (0);
	if (value < 0)
		return (0);
	i = 2;
	fact_nbr = 1;
	while (i <= value)
		fact_nbr = fact_nbr * i++;
	return (fact_nbr);
}
