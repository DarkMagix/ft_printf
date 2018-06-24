/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:33:09 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:33:09 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	is_justify(t_params *params)
{
	params->inc += write(1, "0x", 2);
	params->inc += write(1, params->buff, ft_strlen(params->buff));
	while (params->wid_len > (params->len) + ft_strlen("0x"))
	{
		params->inc += write(1, " ", 1);
		params->wid_len--;
	}
}

void	is_njustify(t_params *params)
{
	while (params->wid_len > (params->len) + ft_strlen("0x"))
	{
		params->inc += write(1, " ", 1);
		params->wid_len--;
	}
	params->inc += write(1, "0x", 2);
	params->inc += write(1, params->buff, ft_strlen(params->buff));
}

void	setup_ptr(va_list list, t_params *params)
{
	params->u = va_arg(list, unsigned long int);
	params->buff = ft_uitoa_base(params->u, 16);
	params->len = ft_strlen(params->buff);
	if (params->justify)
		is_justify(params);
	else
		is_njustify(params);
	free(params->buff);
}
