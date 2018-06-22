/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:06:56 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:32:11 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <locale.h>

void	init_params(t_params *params)
{
	params->justify = false;
	params->plus_neg = false;
	params->spaced = false;
	params->hash = false;
	params->pad = false;
	params->wid_len = 0;
	params->num_len = 0;
	params->has_num_len = false;
	params->p_wildcard = false;
	params->buff = NULL;
	params->specifier = 0;
	params->modifer = 0;
	params->is_neg = false;
	params->u = 0;
	params->i = 0;
	params->zeroes = 0;
	params->spaces = 0;
	params->sign = 0;
	params->inc = 0;
	params->w_s = NULL;
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
		|| c == 'j' || c == 'h' || c == 'i'
		|| c == 'L' || c == 't' || c == 'D'
		|| c == 'C' || c == 'S' || c == 'U'
		|| c == ' ' || c == 'O' || c == '#'
		|| c == '*' || (c >= '0' && c <= '9')));
}

void	ft_parse(int flag, va_list arg, t_params *params)
{
	if (flag == 'S' || (flag == 's' && params->modifer == MODI_l))
		print_wstr(arg, params);
	else if (flag == 's')
		print_str(arg, params);
	else if (flag == 'u' || flag == 'U')
		print_uint(arg, params);
	else if (flag == 'd' || flag == 'D' || flag == 'i')
		print_sint(arg, params, flag);
	else if (flag == 'c')
		print_char(arg);
	else if (flag == '%')
		ft_print_pers(params);
	else if (flag == 'x' || flag == 'X')
		print_hex(arg, params);
	else if (flag == 'o' || flag == 'O')
		print_octal(arg, params);
	else if (flag == 'p')
		setup_ptr(arg, params);
	else if (flag == 'C')
		print_wchar(arg);
}

int		ft_printf(const char *frmt, ...)
{
	va_list		args;
	t_params	*params;
	int			bytes;

	bytes = 0;
	params = ft_memalloc(sizeof(t_params));
	if (frmt)
	{
		va_start(args, frmt);
		bytes += parse_specifier(frmt, args, params);
		va_end(args);
	}
	free(params);
	return (bytes);
}
// int main (void)
// {
// 	ft_printf("\n");
//   ft_printf("%%\n");
//   ft_printf("%d\n", 42);
//   ft_printf("%d%d\n", 42, 41);
//   ft_printf("%d%d%d\n", 42, 43, 44);
//   ft_printf("%ld\n", 2147483647);
//   ft_printf("%lld\n", 9223372036854775807);
//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);
//   ft_printf("%p\n", &ft_printf);
//   ft_printf("%20.15d\n", 54321);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   ft_printf("%hhd\n", 0);
//   ft_printf("%jd\n", 9223372036854775807);
//   ft_printf("%zd\n", 4294967295);
//   ft_printf("%\n");
//   ft_printf("%U\n", 4294967295);
//   ft_printf("%u\n", 4294967295);
//   ft_printf("%o\n", 40);
//   ft_printf("%%#08x\n", 42);
//   ft_printf("%x\n", 1000);
//   ft_printf("%#X\n", 1000);
//   ft_printf("%s\n", NULL);
//   ft_printf("%S\n", L"ݗݜशব");
//   ft_printf("%s%s\n", "test", "test");
//   ft_printf("%s%s%s\n", "test", "test", "test");
//   ft_printf("%C\n", 15000);
//   while (1);
// 	return (0);
// }
// int main(void)
// {

// ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
// 	ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42);
// 	ft_printf("%%*i 42 == |%*i|\n", 5, 42);
// 	ft_printf("%%*i 42 == |%*i|\n", 3, 42);
// 	ft_printf("%%*i 42 == |%*i|\n", 2, 42);

// 	return (0);
// }
// int		main(void)
// {
// 	printf("Numbers\n");
// 	printf("|----Wild Card----|\n");
// 	ft_printf("|%5.*d|\n", 7, 42);
// 	printf("|%5.*d|\n", 7, 42);
// 	ft_printf("|%5.*s|\n", 3, "LYDI");
// 	printf("|%5.*s|\n", 3, "LYDI");
// 	ft_printf("|%3.*s|\n", 0, "LYDI");
// 	printf("|%3.*s|\n", 0, "LYDI");
// 	ft_printf("|%*.3s|\n", 0, "LYDI");
// 	printf("|%*.3s|\n", 0, "LYDI");
// 	printf("|----No Wild Card----|\n");
// 	ft_printf("|%5.7d|\n", 42);
// 	printf("|%5.7d|\n", 42);
// 	ft_printf("|%5.3s|\n", "LYDI");
// 	printf("|%5.3s|\n", "LYDI");
	
// 	// ft_printf("%6.2u\n", 42);
// 	// printf("%6.2u\n", 42);
// 	// ft_printf("|%-5.3s|\n", "Heck");
// 	// printf("|%-5.3s|\n", "Heck");
// 	// ft_printf("|%5.6s|\n", "Heck");
// 	// printf("|%5.6s|\n", "Heck");
// 	// ft_printf("|%1.0s|\n", "Heck");
// 	// printf("|%1.0s|\n", "Heck");
// 	// ft_printf("|%-9.8s|\n", "Heck Me Rotten");
// 	// printf("|%-9.8s|\n", "Heck Me Rotten");
// 	// ft_printf("|%12.8s|\n", "Heck Me Rotten");
// 	// printf("|%12.8s|\n", "Heck Me Rotten");
// 	// ft_printf("|%16.28s|\n", "Heck Me Rotten");
// 	// printf("|%16.28s|\n", "Heck Me Rotten");
// }
