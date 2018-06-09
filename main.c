/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:08:33 by mweir             #+#    #+#             */
/*   Updated: 2018/06/08 17:08:34 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse(int flag, va_list arg, t_params *params)
{
	if (flag == 's')
		print_str(arg);
	else if (flag == 'd')
		print_sint(arg, params);
	else if (flag == 'u')
		print_uint(arg, params);
	else if (flag == 'c')
		print_char(arg);
	else if (flag == '%')
		ft_putchar('%');
	else if (flag == 'x' || flag == 'X')
		print_hex(va_arg(arg, unsigned int), flag);
	else if (flag == 'u')
		print_uint(arg, params);
	else if (flag == 'i')
		print_sint(arg, params);
}

void	ft_printf(const char *frmt, ...)
{
	va_list		args;
	t_params	*params;

	params = ft_memalloc(sizeof(t_params));
	if (frmt)
	{
		va_start(args, frmt);
		parse_specifier(frmt, args, params);
		va_end(args);
	}
}

int		main(void)
{
	printf("Size is %d\n", (int)sizeof(128LL));
	ft_printf("(%+012jd) %s (%-3d)%c\n", 128L, "Space Between Text", 999, '!');
	printf("--------------\n");
	printf("(%+012jd) %s (%-3d)%c\n", 128L, "Space Between Text", 999, '!');
	return (0);
}
