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

intmax_t	sint_flags(va_list list, t_params *params)
{
	intmax_t nbr;

	nbr = va_arg(list, intmax_t);
	if (params->modifer == MODI_HH)
		nbr = (char)nbr;
	else if (params->modifer == MODI_H)
		nbr = (short int)nbr;
	else if (params->modifer == MODI_l)
		nbr = (long int)nbr;
	else if (params->modifer == MODI_ll)
		nbr = (long long int)nbr;
	else if (params->modifer == MODI_J)
		nbr = (intmax_t)nbr;
	else if (params->modifer == MODI_Z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	uint_flags(va_list list, t_params *params)
{
	uintmax_t nbr;

	nbr = va_arg(list, uintmax_t);
	if (params->modifer == MODI_HH)
		nbr = (unsigned char)nbr;
	else if (params->modifer == MODI_H)
		nbr = (unsigned short int)nbr;
	else if (params->modifer == MODI_l)
		nbr = (unsigned long int)nbr;
	else if (params->modifer == MODI_ll)
		nbr = (unsigned long long int)nbr;
	else if (params->modifer == MODI_J)
		nbr = (uintmax_t)nbr;
	else if (params->modifer == MODI_Z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}
