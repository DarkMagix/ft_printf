/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:07:04 by mweir             #+#    #+#             */
/*   Updated: 2018/06/08 17:07:05 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	sint_flags(va_list list, t_params *params)
{
	long long int nbr;

	nbr = va_arg(list, long long int);
	if (params->modifer == MODI_HH)
		nbr = (signed char)nbr;
	else if (params->modifer == MODI_H)
		nbr = (short int)nbr;
	else if (params->modifer == MODI_l)
		nbr = (long int)nbr;
	else if (params->modifer == MODI_ll)
		nbr = (long long int)nbr;
	else if (params->modifer == MODI_J)
		nbr = (intmax_t) nbr;
	else if (params->modifer == MODI_Z)
		nbr = (size_t)nbr;
	return (nbr);
}

unsigned long long int	uint_flags(va_list list, t_params *params)
{
	unsigned long long int nbr;

	nbr = va_arg(list, unsigned long long int);
	if (params->modifer == MODI_HH)
		nbr = (unsigned char)nbr;
	else if (params->modifer == MODI_H)
		nbr = (unsigned short)nbr;
	else if (params->modifer == MODI_l)
		nbr = (unsigned long)nbr;
	else if (params->modifer == MODI_ll)
		nbr = (unsigned long long)nbr;
	else if (params->modifer == MODI_J)
		nbr = (uintmax_t)nbr;
	else if (params->modifer == MODI_Z)
		nbr = (size_t)nbr;
	return (nbr);
}
