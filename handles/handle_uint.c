/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:33:21 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:33:22 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			uint_justify(t_params *params)
{
	if (params->num_len >= params->len && params->justify && params->has_num_len)
	{
		params->zeroes = params->num_len - params->len;
		params->spaces = (params->num_len > params->len) ?
			params->wid_len - params->num_len :
				params->num_len - params->wid_len;
		if (params->num_len == params->len)
			params->spaces = params->wid_len - params->len;
	}
	else if (params->wid_len >= params->len && params->justify && !params->has_num_len)
		params->spaces = params->wid_len - params->len;
}

void			uint_njustify(t_params *params)
{
	if (params->wid_len < params->num_len &&
		!params->justify && params->num_len)
		params->zeroes = params->num_len - params->len;
	else if (params->wid_len > params->len
	&& !params->justify && params->num_len)
	{
		if (params->num_len > params->len)
			params->zeroes = params->num_len - params->len;
		if (params->wid_len == params->len)
			params->zeroes = 0;
		if (params->wid_len > params->num_len + params->zeroes)
			params->spaces = params->wid_len - params->num_len;
	}
	if (params->wid_len > params->len && !params->justify && !params->num_len)
	{
		(!params->pad) ? params->spaces = params->wid_len - params->len : 0;
		(params->pad) ? params->zeroes = params->wid_len - params->len : 0;
	}
}

void			prepare_unint(t_params *params)
{
	if (params->plus_neg)
		params->sign = '+';
	params->buff = ft_uitoa_base(params->u, 10);
	params->len = ft_strlen(params->buff);
	uint_justify(params);
	uint_njustify(params);
}

void			setup_unint(va_list list, t_params *params)
{
	uint_flags(list, params);
	prepare_unint(params);
	if (params->justify)
	{
		print_chars(params, '0', params->zeroes);
		print_nums(params);
		print_chars(params, ' ', params->spaces);
	}
	else
	{
		if (params->sign && !params->pad && (params->inc++))
			ft_putchar(params->sign);
		print_chars(params, ' ', params->spaces);
		print_chars(params, '0', params->zeroes);
		print_nums(params);
	}
	free(params->buff);
}
