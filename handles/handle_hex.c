/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:32:57 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:32:58 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	to_upper(t_params *params)
{
	int i;

	i = -1;
	while (params->buff[++i])
		if (ft_isalpha(params->buff[i]))
			params->buff[i] -= 32;
}
void handle_extra_hex(t_params *params)
{
	(params->plus_neg) ? params->zeroes-- : 0;
	(params->wid_len > params->len + params->zeroes) ?
		params->spaces = params->wid_len - (params->len + params->zeroes) : 0;
	(params->plus_neg && params->pad) ? params->spaces -= 2 : 0;
	(params->spaced && !(IS_NEG(params->u)) && params->spaces == 0) ?
		params->spaces++ : 0;
	(params->hash) ? params->spaces -=2 : 0;
}

void	prepare_hex(t_params *params)
{
	params->buff = ft_uitoa_base(params->u, 16);
	if (params->specifier == 'X')
		to_upper(params);
	params->len = ft_strlen(params->buff);
	if (params->num_len > params->len && params->justify)
		params->zeroes = params->num_len - params->len;
	else if (params->wid_len < params->num_len &&
		!params->justify && params->num_len)
		params->zeroes = params->num_len - params->len;
	else if (params->wid_len > params->len
		&& !params->justify && params->num_len)
	{
		if (params->num_len > params->len)
			params->zeroes = params->num_len - params->len;
		if (params->wid_len == params->len)
			params->zeroes = 0;
	}
	if (params->wid_len > params->len && !params->justify && !params->num_len)
	{
		(!params->pad) ? params->spaces = params->wid_len - params->len : 0;
		if (params->pad)
			params->zeroes = params->wid_len - params->len;
	}
	handle_extra_hex(params);	
}

void	setup_hex(va_list list, t_params *params)
{
	uint_flags(list, params);
	prepare_hex(params);
	if (params->justify)
	{
		if (params->hash)
			params->inc += (params->specifier == 'x') ? (write(1, "0x", 2))
				: (write(1, "0X", 2));
		print_chars(params, '0', params->zeroes);
		print_nums(params);
		params->spaces > 0 ? print_chars(params, ' ', params->spaces) : 0;
	}
	else
	{
		print_chars(params, ' ', params->spaces);
		if (params->hash)
			params->inc += (params->specifier == 'x') ? (write(1, "0x", 2))
				: (write(1, "0X", 2));
		print_chars(params, '0', params->zeroes);
		print_nums(params);
	}
	free(params->buff);
}
