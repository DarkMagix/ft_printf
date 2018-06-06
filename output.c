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

int	print_str(va_list list)
{
	ft_putstr(va_arg(list, char*));
	return (1);
}

int	print_sint(va_list list, t_params *params)
{
	int				i;
	intmax_t num;

	i = 0;
	num = sint_flags(list, params);
	
	
	params->buff = ft_strdup(ft_itoa_base(num, 10));
	ft_format_int(params, (void *)num);
	ft_putstr(params->buff);
	return (1);
}
int print_uint(va_list list, t_params *params)
{
	int i;
	uintmax_t num;
	i = 0;
	num = uint_flags(list, params);
	params->buff = ft_strdup(ft_uitoa_base(num, 10));
	ft_format_int(params, (void *)num);
	ft_putstr(params->buff);
	return (1);
}

int	print_integer(va_list list, t_params *params)
{
	char	sign;
	int		num;
	int		length;

	sign = params->plus_neg;
	length = 0;
	if (params->p_wildcard)
	{
		length = va_arg(list, int);
		params->num_len = length;
	}
	if (params->justify)
	{
		num = va_arg(list, int);
		if (params->plus_neg)
		{
			if (num >= 0)
				ft_putchar('+');
		}
		ft_putnbr(num);
		while (params->num_len > 0)
		{
			ft_putchar((params->pad == true) ? '0' : ' ');
			params->num_len--;
		}
	}
	else
	{
		while (params->num_len > 0)
		{
			ft_putchar((params->pad == true) ? '0' : ' ');
			params->num_len--;
		}
		ft_putnbr(va_arg(list, int));
	}
	return (1);
}

int	print_hex(unsigned int n, int flag)
{
	char hex[16];

	ft_strcpy(hex, "0123456789abcdef");
	if (n >= 16)
		return (print_hex(n / 16, flag) + print_hex(n % 16, flag));
	else
	{
		if (flag == 'x')
			ft_putchar(hex[n]);
		else
			ft_putchar(ft_toupper(hex[n]));
	}
	return (1);
}
