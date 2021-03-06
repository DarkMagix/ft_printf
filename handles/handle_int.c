/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:33:03 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:33:04 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		handle_extra(t_params *params)
{
	(params->plus_neg) ? params->zeroes-- : 0;
	(params->wid_len > params->len + params->zeroes) ?
		params->spaces = params->wid_len - (params->len + params->zeroes) : 0;
	(params->plus_neg && !(params->is_neg)) ? params->sign = '+' : 0;
	(params->plus_neg && (params->is_neg)) ? params->sign = '-' : 0;
	(!params->plus_neg && (params->is_neg)) ? params->sign = '-' : 0;
	(params->plus_neg && params->pad) ? params->spaces -= 2 : 0;
	(params->spaced && !(IS_NEG(params->i)) && params->spaces == 0) ?
		params->spaces++ : 0;
	params->spaces += (params->spaced && params->plus_neg) ? -1 : 0;
	if (params->sign == '-')
		params->spaces--;
	if (params->wid_len > params->num_len && params->has_num_len)
		(params->plus_neg && params->num_len
			> params->len) ? params->zeroes++ : 0;
	params->zeroes += (!params->plus_neg && params->pad
		&& params->wid_len > params->len && !params->has_num_len) ? -2 : 0;
	if (params->wid_len > params->len && !params->has_num_len && params->pad)
	{
		params->zeroes = params->wid_len - params->len;
		if (params->wid_len + params->pad > params->len)
			(params->sign == '-' || params->sign == '+') ? params->zeroes-- : 0;
	}
}

void		pre_check(t_params *params)
{
	params->is_neg = (IS_NEG(params->i)) ? true : false;
	params->i *= (IS_NEG(params->i)) ? -1 : 1;
	params->buff = ft_itoa_base(params->i, 10);
	params->len = ft_strlen(params->buff);
	(params->wid_len < 0) ? params->justify = true : 0;
	(params->wid_len < 0) ? params->wid_len *= -1 : 0;
}

static void	prepare_int(t_params *params)
{
	pre_check(params);
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
	handle_extra(params);
}

void		check_sign(t_params *params)
{
	if (params->sign)
	{
		ft_putchar(params->sign);
		params->inc++;
	}
}

void		setup_int(va_list list, t_params *params)
{
	if (params->specifier == 'D')
		params->modifer = MODI_ll;
	sint_flags(list, params);
	prepare_int(params);
	if (params->justify && params->pad)
		params->pad = false;
	if (!params->justify)
	{
		print_chars(params, ' ', params->spaces);
		check_sign(params);
		print_chars(params, '0', params->zeroes);
		print_nums(params);
	}
	else
	{
		check_sign(params);
		print_chars(params, '0', params->zeroes);
		print_nums(params);
		print_chars(params, ' ', params->spaces);
	}
	free(params->buff);
}
