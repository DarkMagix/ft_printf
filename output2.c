/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:32:36 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:32:37 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_wchar(va_list list, t_params *params)
{
	int		i;
	wchar_t	let;

	i = 0;
	let = va_arg(list, wchar_t);
	params = NULL;
	ft_wputchar(let);
	return (i);
}

int	print_wstr(va_list list, t_params *params)
{
	ft_putwstr(list, params);
	return (1);
}

int	print_octal(va_list list, t_params *params)
{
	setup_octal(list, params);
	return (params->inc);
}
