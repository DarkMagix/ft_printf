/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:20:35 by mweir             #+#    #+#             */
/*   Updated: 2018/06/22 17:20:36 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			oct_justify(t_params *params)
{
	if (params->num_len >= params->len
		&& params->justify && params->has_num_len)
	{
		params->zeroes = params->num_len - params->len;
		params->spaces = (params->num_len > params->len) ?
			params->wid_len - params->num_len :
				params->num_len - params->wid_len;
		if (params->num_len == params->len)
			params->spaces = params->wid_len - params->len;
	}
	else if (params->wid_len >= params->len
		&& params->justify && !params->has_num_len)
		params->spaces = params->wid_len - params->len;
	if (params->hash)
	{
		(params->len < params->wid_len &&
			!params->has_num_len) ? params->zeroes++ : 0;
		(params->len < params->wid_len &&
			!params->has_num_len) ? params->spaces-- : 0;
		if (params->len > params->num_len && params->has_num_len)
		{
			params->spaces++;
			params->zeroes = params->wid_len - params->spaces - params->len;
		}
	}
}

void			n_justify_hash(t_params *params)
{
	if (params->hash)
	{
		(params->has_num_len && params->num_len < params->wid_len)
			? params->spaces++ : 0;
		(params->has_num_len) ? (params->spaces = params->wid_len
			- params->len - params->zeroes) : params->spaces--;
		(params->len > params->num_len) ? params->zeroes++ : 0;
		(params->len == 1 && params->num_len == 0 &&
			params->wid_len == 0) ? params->zeroes-- : 0;
		(params->len > params->num_len &&
			params->has_num_len) ? params->spaces-- : 0;
	}
}

void			oct_njustify(t_params *params)
{
	if (params->wid_len < params->num_len && params->num_len)
		params->zeroes = params->num_len - params->len;
	else if (params->wid_len > params->len
	&& !params->justify && params->num_len)
	{
		(params->num_len > params->len) ? params->zeroes =
			params->num_len - params->len : 0;
		(params->wid_len == params->len) ? params->zeroes = 0 : 0;
		if (params->wid_len > params->num_len + params->zeroes)
			params->spaces = params->wid_len - params->num_len;
	}
	if (params->wid_len > params->len && !params->justify && !params->num_len)
	{
		(!params->pad) ? params->spaces = params->wid_len - params->len : 0;
		(params->pad) ? params->zeroes = params->wid_len - params->len : 0;
	}
	n_justify_hash(params);
}

void			prepare_octal(t_params *params)
{
	if (params->plus_neg)
		params->sign = '+';
	params->buff = ft_uitoa_base(params->u, 8);
	params->len = ft_strlen(params->buff);
	if (params->justify)
		oct_justify(params);
	else
		oct_njustify(params);
}

void			setup_octal(va_list list, t_params *params)
{
	uint_flags(list, params);
	prepare_octal(params);
	if (params->justify)
	{
		print_chars(params, '0', params->zeroes);
		print_nums(params);
		print_chars(params, ' ', params->spaces);
	}
	else
	{
		print_chars(params, ' ', params->spaces);
		print_chars(params, '0', params->zeroes);
		print_nums(params);
	}
	free(params->buff);
}
