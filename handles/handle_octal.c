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

void	prepare_octal(t_params *params)
{
	params->buff = ft_uitoa_base(params->u, 8);
	params->len = ft_strlen(params->buff);
	if (params->hash && params->buff[0] != '0')
		params->zeroes++;
	if (params->num_len > params->len + params->zeroes)
		params->zeroes = params->num_len - params->len;
	if (params->justify)
		params->spaces = params->wid_len - (params->zeroes + params->len);
	else
	{
		if (params->num_len < params->wid_len + params->zeroes)
		{
			params->spaces = (params->num_len >= params->len) ?
				params->wid_len - params->len
				: params->wid_len - params->num_len;
			if (params->len > params->num_len
			|| params->num_len == params->len + 1)
				params->spaces--;
		}
		if (params->wid_len + params->zeroes > params->num_len)
			params->spaces = params->wid_len - params->num_len;
		if (params->num_len >= params->wid_len + params->len)
			params->spaces = 0;
	}
}

void	setup_octal(va_list list, t_params *params)
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
