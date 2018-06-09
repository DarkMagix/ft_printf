/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:06:56 by mweir             #+#    #+#             */
/*   Updated: 2018/06/08 17:52:23 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_params(t_params *params)
{
	params->justify = false;
	params->plus_neg = false;
	params->spaced = false;
	params->hash = false;
	params->pad = false;
	params->wid_len = 0;
	params->num_len = 0;
	params->p_wildcard = false;
	params->buff = NULL;
	params->specifier = 0;
	params->modifer = 0;
	params->is_neg = false;
}

int		valid_arg(int c)
{
	return ((c == 'd' || c == 'u' || c == 'o'
		|| c == 'x' || c == 'X' || c == 'f'
		|| c == 'F' || c == 'e' || c == 'E'
		|| c == 'g' || c == 'G' || c == 'a'
		|| c == 'A' || c == 'c' || c == 's'
		|| c == 'p' || c == 'n' || c == '%'
		|| c == '.' || c == '-' || c == '0'
		|| c == '+' || c == 'l' || c == 'z'
		|| c == 'j' || (c >= '0' && c <= '9')));
}

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

int main(void)
{
	intmax_t b = 30000;
	ft_printf("%jd", b);
	return (0);
}
