/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:06:56 by mweir             #+#    #+#             */
/*   Updated: 2018/06/08 19:26:50 by mweir            ###   ########.fr       */
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
	params->has_len = false;
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
		|| c == 'j' || c == 'h' || c == 'i'
		|| c == 'L' || c == 't' || c == 'D'
		|| c == '*' || c == 'C' || c == 'S'
		|| c == ' ' || c == 'O' || (c >= '0' && c <= '9')));
}

void	ft_parse(int flag, va_list arg, t_params *params)
{
	if (flag == 's')
		print_str(arg);
	else if (flag == 'D')
	  {
	    params->modifer = MODI_L;
	    print_uint(arg, params);
	  }
	else if (flag == 'd' || flag == 'D')
	   print_sint(arg, params);
	else if (flag == 'u')
		print_uint(arg, params);
	else if (flag == 'c')
		print_char(arg);
	else if (flag == '%')
		ft_putchar('%');
	else if (flag == 'x' || flag == 'X')
		print_hex(va_arg(arg, unsigned int), flag);
	else if (flag == 'o' || flag == 'O')
		print_octal(arg, params);
	else if (flag == 'i')
		print_sint(arg, params);
	else if (flag == 'p')
		print_ptr(arg, params);
	else if (flag == 'C')
		print_wchar(arg, params);
	else if (flag == 'S')
		print_wstr(arg, params);
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
	free(params);
}
//int main (void)
//{
  //  ft_printf("| %      i|", 42);
  //  printf("\n");
  //  printf("| %      i|\n", 42);
  
  //  ft_printf("|% i|", -42);
  //  printf("\n");
  //  printf("|% i|\n", -42);
  
  //  ft_printf("|% 4i|", 42 );
  //  printf("\n");
  //  printf("|% 4i|\n", 42 );
  
  //  return(0);
  //     }	
       
//int main(void)
//{
  //	unsigned int a;
	//	unsigned char b;	
	//	unsigned short int c;
	//	unsigned long int d;
	//	unsigned long long int e;
	//	uintmax_t f;
	//	size_t g;
	
	//	a = 4294967295;
	//	b = 255;
	//	c = 65535;
	//	d = 4294967295;
	//	e = 1844674407370955161;
	//	f = 1844674407370955161;
	//	g = 1844674407370955161;
	
	

	//	ft_printf("|%-u|\n", a);
	//	printf("|%-u|\n", a);
	//	ft_printf("|%-hhu|\n", b);
	//	printf("|%-hhu|\n", b);
	//	ft_printf("|%-hu|\n", c);
	//	printf("|%-hu|\n", c);
	//	ft_printf("|%-lu|\n", d);
	//	printf("|%-lu|\n", d);
	//	ft_printf("|%-llu|\n", e);
	//	printf("|%-llu|\n", e);
	//	ft_printf("|%-ju|\n", f);
	//	printf("|%-ju|\n", f);
	//	ft_printf("|%-zu|\n", g);
	//	printf("|%-zu|\n", g);
	//	while(1)
	//	;
	
	//	return (0);
	//}
