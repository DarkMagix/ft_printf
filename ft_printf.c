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
	params->has_len = false;
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
// int main(void)
// {
// 	ft_printf("%c", 42);
// 	ft_printf("Kashim a %c histoires à raconter", 1001);
// 	ft_printf("Il fait au moins %c\n", -8000);
// 	ft_printf("%c", -0);
// 	ft_printf("%c", 0);
// 	ft_printf("%c\n", INT_MAX);
// 	ft_printf("%c\n", 'c');
// 	ft_printf("%c\n", '\n');
// 	ft_printf("%c", 'l');
// 	ft_printf("%c", 'y');
// 	ft_printf("%c", ' ');
// 	ft_printf("%c", 'e');
// 	ft_printf("%c", 's');
// 	ft_printf("%c", 't');
// 	ft_printf("%c", ' ');
// 	ft_printf("%c", 'f');
// 	ft_printf("%c", 'a');
// 	ft_printf("%c", 'n');
// 	ft_printf("%c", 't');
// 	ft_printf("%c", 'a');
// 	ft_printf("%c", 's');
// 	ft_printf("%c", 't');
// 	ft_printf("%c", 'i');
// 	ft_printf("%c", 'q');
// 	ft_printf("%c", 'u');
// 	ft_printf("%c", 'e');
// 	ft_printf("%c\n", '!');
// 	ft_printf("%c\n", '\r');
// 	ft_printf("%c\n", '\t');
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
