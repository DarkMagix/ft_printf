
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:06:56 by mweir             #+#    #+#             */
/*   Updated: 2018/06/12 18:27:42 by mweir            ###   ########.fr       */
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
		|| c == '*' || c == 'C' || c == 'S'
		|| c == ' ' || c == 'O' || c == '#'
		|| (c >= '0' && c <= '9')));
}

void	ft_parse(int flag, va_list arg, t_params *params)
{
	if (flag == 's')
		print_str(arg, params);
	else if (flag == 'D' || flag == 'u')
	  {
	    params->modifer = (flag == 'D') ? MODI_L : params->modifer;
	    print_uint(arg, params);
	  }
	else if (flag == 'd' || flag == 'D' || flag == 'i')
	   print_sint(arg, params);
	else if (flag == 'c')
		print_char(arg);
	else if (flag == '%')
	{
		ft_putchar('%');
		params->inc++;
	}
	else if (flag == 'x' || flag == 'X')
		print_hex(arg, params);
	else if (flag == 'o' || flag == 'O')
		print_octal(arg, params);
	else if (flag == 'p')
		setup_ptr(arg, params);
	else if (flag == 'C')
		print_wchar(arg, params);
	else if (flag == 'S')
		print_wstr(arg, params);
		//print_wstr(arg, params);
}

int	ft_printf(const char *frmt, ...)
{
	va_list		args;
	t_params	*params;
	int bytes;
	
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
// // ft_printf("%+i\n", 42);// == +42
// // printf("%+i\n", 42);// == +42
// // ft_printf("%+d\n", 42);// == +2147483647
// // printf("%+d\n", 42);// == +2147483647
// // ft_printf("%+i\n", -42);// == -42
// // printf("%+i\n", -42);// == -42
// // ft_printf("%+04d\n", 42);// == +042
// // printf("%+04d\n", 42);// == +042

// //ft_printf("%-5.3s LYDI == |LYD  |

// // ft_printf("Me: % 4.5i\n", 42);// == | 00042|
// // printf("Them: % 4.5i\n", 42);// == | 00042|
// // printf("Justified\n");
// // ft_printf("Me: %-4.5i\n", 42);// == |00042|
// // printf("Them: %-4.5i\n", 42);// == |00042|
// // ft_printf("Me %-4.3i\n", 42);// == | 042|
// // printf("Them %-4.3i\n", 42);// == | 042|
// // ft_printf("Me %-4.2i\n", 42);// == |  42|
// // printf("Them %-4.2i\n", 42);// == |  42|


// ft_printf("|% 4.5i|\n", 42);// == | 00042|
// printf("|% 4.5i|\n", 42);// == | 00042|
// printf("Not Justified\n");
// ft_printf("|%04.5i|\n", 42);// == |00042|
// printf("|%04.5i|\n", 42);// == |00042|
// ft_printf("|%04.3i|\n", 42);// == | 042|
// printf("|%04.3i|\n", 42);// == | 042|
// ft_printf("|%04.2i|\n", 42);// == |  42|
// printf("|%04.2i|\n", 42);// == |  42|
// printf("Justified\n");
// ft_printf("|%-4.2i|\n", 42);// == |  42|
// printf("|%-4.2i|\n", 42);// == |  42|
// ft_printf("|%-+4.2i|\n", 42);// == |  42|
// printf("|%-+4.2i|\n", 42);// == |  42|
// // printf("%-10.5d", 100);
// }
