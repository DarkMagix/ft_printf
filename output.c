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

int	print_char(va_list list, t_params *params)
{
	char c;
	
	c = va_arg(list, int);
	//printf("C %c", c);
	if (params->wid_len < 0)
	{
		params->justify = true;
		params->wid_len *= -1;
	}
	if (params->num_len == 0 && params->wid_len == 0)
		params->inc++;
	justify_chars(params, c);
	params->inc += (params->num_len > 0) ? 1 : 0;
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

int	print_uint(va_list list, t_params *params, int flag)
{
	params->modifer = (flag == 'U') ? MODI_l : params->modifer;
	setup_unint(list, params);
	return (1);
}

int	print_hex(va_list list, t_params *params)
{
	setup_hex(list, params);
	return (params->inc);
}
