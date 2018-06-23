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
		print_char(arg, params);
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
		params->inc += bytes;
		va_end(args);
	}
	free(params);
	return (bytes);
}
int main(void)
{
  //  ft_printf("|%7u|\n",42);
  //  printf("|%7u|\n",42);
  ft_printf("Me\t7.3o\t|%7.3o|\n", 42);
  printf("Them\t7.3o\t|%7.3o|\n", 42);
  ft_printf("Me\t7.9o\t|%7.9o|\n", 42);
  printf("Them\t7.9o\t|%7.9o|\n", 42);
  printf("\n-------------\n");
  printf("Them\t7.1o\t|%7.1o|\n", 42);
  ft_printf("Me\t7.1o\t|%7.1o|\n", 42);
  printf("Them\t7.2o\t|%7.2o|\n", 42);
  ft_printf("Me\t7.2o\t|%7.2o|\n", 42);
  printf("-------------\n");
  ft_printf("|%7.3x|\n", 42);
  printf("|%7.3x|\n", 42);
  ft_printf("|%7.9x|\n", 42);
  printf("|%7.9x|\n", 42);
  printf("---------------\n");
  printf("\nJustify\n");
  ft_printf("|%-7.3x|\n", 42);
  printf("|%-7.3x|\n", 42);
  ft_printf("|%-7.9x|\n", 42);
  printf("|%-7.9x|\n", 42);
  printf("\nJustify Octal\n");
  ft_printf("|%-7.3o|\n", 42);
  printf("|%-7.3o|\n", 42);
  ft_printf("|%-7.9o|\n", 42);
  printf("|%-7.9o|\n", 42);
  printf("\nJustify with Hash\n");
  ft_printf("|%-#7.3x|\n", 42);
  printf("|%-#7.3x|\n", 42);
  ft_printf("|%-#7.9x|\n", 42);
  printf("|%-#7.9x|\n", 42);
  printf("\nJustify Octal\n");
  ft_printf("|%-#7.3o|\n", 42);
  printf("|%-#7.3o|\n", 42);
  ft_printf("|%-#7.9o|\n", 42);
  printf("|%-#7.9o|\n", 42);
  printf("\nUnsigned Non-Justify\n");
  printf("Them:\t3.4u\t|%3.4u|\n", 420);
  ft_printf("Me:\t3.4u\t|%3.4u|\n", 420);
  printf("Them:\t7.4u\t|%7.4u|\n", 420);
  ft_printf("Me:\t7.4u\t|%7.4u|\n", 420);
  printf("Them:\t7.3u\t|%7.3u|\n", 420);
  ft_printf("Me:\t7.3u\t|%7.3u|\n", 420);
  printf("Them:\t3.7u\t|%3.7u|\n", 420);
  ft_printf("Me:\t3.7u\t|%3.7u|\n", 420);
  printf("Them:\t3.3u\t|%3.3u|\n", 420);
  ft_printf("Me:\t3.3u\t|%3.3u|\n", 420);
  printf("Them:\t9.9u\t|%9.9u|\n", 420);
  ft_printf("Me:\t9.9u\t|%9.9u|\n", 420);
  printf("Them:\t2.2u\t|%2.2u|\n", 420);
  ft_printf("Me:\t2.2u\t|%2.2u|\n", 420);
  printf("Unsigned Justified\n");
  printf("Them:\t-7.4u\t|%-7.4u|\n", 420);
  ft_printf("Me:\t-7.4u\t|%-7.4u|\n", 420);
  printf("Them:\t-7.3u\t|%-7.3u|\n", 420);
  ft_printf("Me:\t-7.3u\t|%-7.3u|\n", 420);
  printf("Them:\t-3.7u\t|%-3.7u|\n", 420);
  ft_printf("Me:\t-3.7u\t|%-3.7u|\n", 420);
  printf("Them:\t-3.3u\t|%-3.3u|\n", 420);
  ft_printf("Me:\t-3.3u\t|%-3.3u|\n", 420);
  printf("Them:\t-9.9u\t|%-9.9u|\n", 420);
  ft_printf("Me:\t-9.9u\t|%-9.9u|\n", 420);
  printf("Them:\t-2.2u\t|%-2.2u|\n", 420);
  ft_printf("Me:\t-2.2u\t|%-2.2u|\n", 420);
  ft_printf("\n\t|String\t|\n");
  char *str = "This is a message";
  int size = ft_strlen(str);
  ft_printf("Me\t7.5\t|%7.5s|\n", str);
  printf("Me\t7.5\t|%7.5s|\n", str);
  ft_printf("Me\t20.20\t|%20.20s|\n", str);
  printf("Me\t20.20\t|%20.20s|\n", str);
  ft_printf("Me\t5.5\t|%5.5s|\n", str);
  printf("Me\t5.5\t|%5.5s|\n", str);
  //  ft_printf("Me\t0.0\t|%0.0s|\n", str);
  //  printf("Me\t0.0\t|%0.0s|\n", str);
  ft_printf("Me\t%d.%d\t|%*.*s|\n",size, size, size, size,str);
  printf("Me\t%d.%d\t|%*.*s|\n",size, size, size, size, str);

  //  ft_printf("|%7.3x|\n", 42);
  //  printf("|%7.3x|\n", 42);
  //  ft_printf("|%7.3d|\n", 42);
  //  printf("|%7.3d|\n", 42);
  return (0);
}
//int main(void)
//{
//  ft_printf("%d", 42);
//  ft_printf("Kashim a %d histoires à raconter", 1001);
//  ft_printf("Il fait au moins %d\n", -8000);
//  ft_printf("%d", -0);
//  ft_printf("%d", 0);
//  ft_printf("%d", INT_MAX);
//  ft_printf("%d", INT_MIN);
//  ft_printf("%d", INT_MIN - 1);
//  ft_printf("%d", INT_MAX + 1);
//  ft_printf("%%d 0000042 == |%d|\n", 0000042);
//  ft_printf("%%d \t == |%d|\n", '\t');
//  ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
//
//  ft_printf("%%      i 42 == |%      i|\n", 42);
//  printf("%%      i 42 == |%      i|\n", 42);
//  ft_printf("%% i -42 == |% i|\n", -42);
//  printf("%% i -42 == |% i|\n", -42);
//  ft_printf("%% 4i 42 == |% 4i|\n", 42);
//  printf("%% 4i 42 == |% 4i|\n", 42);
//  return (0);
//}
//int main(void)
//{
  //  ft_printf("%+d\n", -42);// == -42
  //  printf("%+d\n", -42);
  //  ft_printf("%+04d\n", 42);// == +042
  //  printf("%+04d\n", 42);
  //  ft_printf("%-+04d\n", -42);
  //  printf("%-+04d\n", -42);
  //  ft_printf("%-+04d\n", 42);
  //  printf("%-+04d\n", 42);
  //  return (0);
  // }
//int main(void)
//{
//  ft_printf("|%07.4d|\n", 42);
//  printf("|%07.4d|\n", 42);
//  ft_printf("|%-07.4d|\n", 42);
//  printf("|%-07.4d|\n", 42);
//  ft_printf("|%07.4d|\n", 42);
//  printf("|%07.4d|\n", 42);
//  ft_printf("|%-7.8d|\n", -42);
//  printf("|%-7.8d|\n", -42);
//  ft_printf("+\n");
//  ft_printf("%d", 42);
//  ft_printf("Kashim a %d histoires à raconter", 1001);
//  ft_printf("Il fait au moins %d\n", -8000);
//  ft_printf("%d", -0);
//  ft_printf("%d", 0);
//  ft_printf("%d", INT_MAX);
//  ft_printf("%d", INT_MIN);
//  ft_printf("%d", INT_MIN - 1);
//  ft_printf("%d", INT_MAX + 1);
//  ft_printf("%%d 0000042 == |%d|\n", 0000042);
//  ft_printf("%%d \t == |%d|\n", '\t');
//  ft_printf("%%d Lydie == |%d|\n", 'L'+'y'+'d'+'i'+'e');
//  ft_printf("-\n");
//  ft_printf("%%-i 42 == %-i\n", 42);
//  ft_printf("%%-d 42 == %-d\n", INT_MIN);
//  ft_printf("%%-i -42 == %-i\n", -42);
//  ft_printf("%%-4d 42 == |%-4d|\n", 42);
//  ft_printf("%%-5d -42 == |%-5d|\n", -42);
//  ft_printf("|%3i|%-3i|\n", 42, 42);
//  ft_printf("%%-4i 42 == |%-4i|\n", 42);
//  
//  return (0);
//}
// int		main(void)
// {
// 	printf("Decimal\n");
// 	ft_printf("|%10d|\n", 42);
// 	printf("|%10d|\n", 42);
// 	ft_printf("|%-10d|\n", 42);
// 	printf("|%-10d|\n", 42);
// 	ft_printf("|%10d|\n", 42);
// 	printf("|%10d|\n", 42);
// 	ft_printf("|%-10d|\n", 42);
// 	printf("|%-10d|\n", 42);
// 	ft_printf("|%010.5d|\n", 542);
// 	printf("|%010.5d|\n", 542);
// 	printf("Hex\n");
// 	ft_printf("|%10x|\n", 42);
// 	printf("|%10x|\n", 42);
// 	ft_printf("|%-#10x|\n", 42);
// 	printf("|%-#10x|\n", 42);
// 	ft_printf("|%#10x|\n", 42);
// 	printf("|%#10x|\n", 42);
// 	ft_printf("|%-10x|\n", 42);
// 	printf("|%-10x|\n", 42);
// 	ft_printf("|%010.5x|\n", 542);
// 	printf("|%010.5x|\n", 542);
// 	return (0);
// }
