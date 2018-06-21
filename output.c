/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:00:16 by mweir             #+#    #+#             */
/*   Updated: 2018/06/04 15:05:43 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list list)
{
	ft_putchar(va_arg(list, int));
	return (1);
}

int	print_str(va_list list, t_params *params)
{
	ft_putstring(list, params);
	return (1);
}

int	print_sint(va_list list, t_params *params, int flag)
{
	params->modifer = (flag == 'D') ? MODI_L : params->modifer;
	setup_int(list, params);
	
	return (1);
}

int	print_uint(va_list list, t_params *params)
{
	setup_unint(list, params);
	
	return (1);
}

int	print_hex(va_list list, t_params *params)
{
 	setup_hex(list, params);
  	return (params->inc);
}
