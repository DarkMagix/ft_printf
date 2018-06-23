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

static void		prepare_unint(t_params *params)
{
	if (params->plus_neg)
		params->sign = '+';
	params->buff = ft_uitoa_base(params->u, 10);
	params->len = ft_strlen(params->buff);
	if (params->num_len > params->len)
		params->zeroes = params->num_len - params->len;
	if (params->wid_len > params->len + params->zeroes)
		params->spaces = params->wid_len - (params->len + params->zeroes);
}

void			setup_unint(va_list list, t_params *params)
{
	if (params->specifier == 'U')
		params->modifer = MODI_l;
	uint_flags(list, params);
	prepare_unint(params);
	if (params->justify)
	{
		if (params->sign && (params->inc++))
			ft_putchar('0');
		print_chars(params, '0', params->zeroes);
		print_nums(params);
		print_chars(params, ' ', params->spaces);
	}
	else
	{
		if (params->sign && !params->pad && (params->inc++))
			ft_putchar(params->sign);
		(params->pad) ? print_chars(params, '0', params->spaces)
			: print_chars(params, ' ', params->spaces);
		print_chars(params, '0', params->zeroes);
		print_nums(params);
	}
	free(params->buff);
}
