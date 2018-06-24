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
	else if (flag == 'u' || (flag == 'U'))
		print_uint(arg, params, flag);
	else if (flag == 'd' || flag == 'D' || flag == 'i')
		print_sint(arg, params, flag);
	else if (flag == 'c')
		print_char(arg, params);
	else if (flag == '%')
		ft_print_pers(params);
	else if (flag == 'x' || flag == 'X')
		print_hex(arg, params);
	else if (flag == 'o' || flag == 'O')
		print_octal(arg, params, flag);
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
		params->inc += bytes;
		va_end(args);
	}
	free(params);
	return (bytes);
}
// int main(void)
// {
// 	// ft_printf("%S\n",L"Á±≥");
// 	// printf("%lsn",L"Á±≥");
// 	//char c = NULL;
// 	ft_printf("%d\t\n", ft_printf("{%.c}\n", 97));
// 	ft_printf("%d\t\n" ,printf("{%.c}\n", 97));
	

// 	ft_printf("{%*.*d}\n", 3,-5, 4200);
// 	printf("{%*.*d}\n",3, -5, 4200);
// 	ft_printf("{%*.*d}\n", 6,-5, 4200);
// 	printf("{%*.*d}\n",6, -5, 4200);
// 	//printf("|%1.d|\n", 0);
// // printf("Non Justified u and o\n");
// // ft_printf("Me\t7u\t|%7u|\n",42);
// // printf("Them\t7u\t|%7u|\n",42);
// // ft_printf("Me\t7o\t|%7o|\n",42);
// // printf("Them\t7o\t|%7o|\n",42);
// // printf("Non JUstified u and o\n");
// // ft_printf("Me\t-7u\t|%-7u|\n",42);
// // printf("Them\t-7u\t|%-7u|\n",42);
// // ft_printf("Me\t-7o\t|%-7o|\n",42);
// // printf("Them\t-7o\t|%-7o|\n",42);
// // printf("Precision u and o\n");
// // ft_printf("Me\t7.3o\t|%7.3o|\n", 42);
// // printf("Them\t7.3o\t|%7.3o|\n", 42);
// // ft_printf("Me\t7.9o\t|%7.9o|\n", 42);
// // printf("Them\t7.9o\t|%7.9o|\n", 42);
// // ft_printf("Me\t0.9o\t|%0.9o|\n", 42);
// // printf("Them\t0.9o\t|%0.9o|\n", 42);
// // ft_printf("Me\t15.9o\t|%15.9o|\n", 42);
// // printf("Them\t15.9o\t|%15.9o|\n", 42);
// // ft_printf("Me\t9.15o\t|%9.15o|\n", 42);
// // printf("Them\t9.15o\t|%9.15o|\n", 42);

// // unsigned long int a = 42;
// // printf("|\tNon Justified U and O\t|\n");
// // ft_printf("Me\t7U\t|%7U|\n",42);
// // printf("Them\t7U\t|%7lu|\n",a);
// // ft_printf("Me\t7.3O\t|%7.3O|\n", 42);
// // printf("Them\t7.3lo\t|%7.3lo|\n", a);
// // ft_printf("Me\t7.9O\t|%7.9O|\n", 42);
// // printf("Them\t7.9lo\t|%7.9lo|\n", a);
// // ft_printf("Me\t0.9O\t|%0.9lo|\n", 42);
// // printf("Them\t0.9lo\t|%0.9lo|\n", a);
// // ft_printf("Me\t15.9O\t|%15.9O|\n", 42);
// // printf("Them\t15.9lo\t|%15.9lo|\n", a);
// // ft_printf("Me\t9.15O\t|%9.15O|\n", 42);
// // printf("Them\t9.15lo\t|%9.15lo|\n", a);

// // printf("\nJustified U and O\n");
// // ft_printf("Me\t-7u\t|%-7u|\n",42);
// // printf("Them\t-7u\t|%-7u|\n",42);
// // ft_printf("Me\t-7.3o\t|%-7.3o|\n", 42);
// // printf("Them\t-7.3o\t|%-7.3o|\n", 42);
// // ft_printf("Me\t-7.9o\t|%-7.9o|\n", 42);
// // printf("Them\t-7.9o\t|%-7.9o|\n", 42);
// // ft_printf("Me\t-15.9o\t|%-15.9o|\n", 42);
// // printf("Them\t-15.9o\t|%-15.9o|\n", 42);
// // ft_printf("Me\t-9.15o\t|%-9.15o|\n", 42);
// // printf("Them\t-9.15o\t|%-9.15o|\n", 42);

//  return (0);
// }
