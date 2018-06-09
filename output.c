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
	int		i;
	char	*test;

	i = 0;
	test = va_arg(list, char*);
	while (test[i])
	{
		ft_putchar(test[i]);
		i++;
	}
	return (1);
}

int	print_sint(va_list list, t_params *params)
{
	intmax_t num;
	char *number;
	num = sint_flags(list, params);
	params->is_neg = (num < 0) ? true : false;
	num = (params->is_neg) ? -num : num;
	number =ft_itoa_base(num, 10);
	params->buff = number;
	ft_format_int(params);
	ft_putstr(params->buff);
        free(params->buff);
	free(number);
	return (1);
}

int	print_uint(va_list list, t_params *params)
{
	uintmax_t num;

	num = uint_flags(list, params);
	params->buff = ft_strdup(ft_uitoa_base(num, 10));
	ft_format_int(params);
	ft_putstr(params->buff);
	free(params->buff);
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
