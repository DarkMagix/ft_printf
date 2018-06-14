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

int	print_str(va_list list, t_params *params)
{
	int		i;
	int		j;
	char	*test;

	j = 0;
	i = 0;
	test = va_arg(list, char*);
	params->buff = test;
	format_str(params);
	while (params->buff[j])
	{
		ft_putchar(params->buff[j]);
		j++;
	}

	return (1);
}

int	print_sint(va_list list, t_params *params)
{
	intmax_t	num;
	char		*number;

	num = sint_flags(list, params);
	params->is_neg = (num < 0) ? true : false;
	num = (params->is_neg) ? -num : num;
	number = ft_itoa_base(num, 10);
	params->buff = number;
	ft_format_int(params);
	ft_putstr(params->buff);
	free(params->buff);
	free(number);
	return (1);
}

int	print_uint(va_list list, t_params *params)
{
	uintmax_t	num;
	char		*number;

	num = uint_flags(list, params);
	number = ft_uitoa_base(num, 10);
	params->buff = number;
	ft_format_int(params);
	ft_putstr(params->buff);
	free(params->buff);
	free(number);
	return (1);
}

int	print_hex(va_list list, t_params *params)
{
  uintmax_t       num;
  char            *number;
  
  num = uint_flags(list, params);
  number = ft_uitoa_base(num, 16);
  params->buff = number;
  format_hex(params);
  ft_putstr(params->buff);
  free(params->buff);
  free(number);
  return (1);
}
