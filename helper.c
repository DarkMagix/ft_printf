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

void	sint_flags(va_list list, t_params *params)
{
	if (params->modifer == MODI_HH)
		params->i = (signed char)va_arg(list, long long int);
	else if (params->modifer == MODI_H)
		params->i = (short)va_arg(list, long long int);
	else if (params->modifer == MODI_l)
		params->i = (long)va_arg(list, long long int);
	else if (params->modifer == MODI_ll)
		params->i = (long long)va_arg(list, long long int);
	else if (params->modifer == MODI_J)
		params->i = (intmax_t)va_arg(list, long long int);
	else if (params->modifer == MODI_Z)
		params->i = (size_t)va_arg(list, long long int);
	else
		params->i = (int)va_arg(list, long long int);
}

void	uint_flags(va_list list, t_params *params)
{
	if (params->modifer == MODI_HH)
		params->u = (unsigned char)va_arg(list, unsigned long long int);
	else if (params->modifer == MODI_H)
		params->u = (unsigned short)va_arg(list, unsigned long long int);
	else if (params->modifer == MODI_l)
		params->u = (unsigned long)va_arg(list, unsigned long long int);
	else if (params->modifer == MODI_ll)
		params->u = (unsigned long long)va_arg(list, unsigned long long int);
	else if (params->modifer == MODI_J)
		params->u = (uintmax_t)va_arg(list, unsigned long long int);
	else if (params->modifer == MODI_Z)
		params->u = (size_t)va_arg(list, unsigned long long int);
	else
		params->u = (unsigned int)va_arg(list, unsigned long long int);
}
