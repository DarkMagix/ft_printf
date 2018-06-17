
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
	params->u = 0;
	params->i = 0;
	params->zeroes = 0;
	params->spaces = 0;
	params->sign = 0;
	params->inc = 0;
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
		ft_putchar('%');
	else if (flag == 'x' || flag == 'X')
		print_hex(arg, params);
	else if (flag == 'o' || flag == 'O')
		print_octal(arg, params);
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
int main(void)
{
	unsigned long int max = 2147483647;
	unsigned long int min = -2147483648;

	// char *b = NULL;
	// ft_printf("|% 4.5i|\n", 42);// == | 00042|
	// printf("|% 4.5i|\n", 42);// == | 00042|
	
	// ft_printf("|%04.5i|\n", 42);// == |00042|
	// printf("|%04.5i|\n", 42);// == |00042|
	
	// ft_printf("|%04.3i|\n", 42);// == | 042|
	// printf("|%04.3i|\n", 42);// == | 042|
	
	// ft_printf("|%04.2i|\n", 42);// == |  42|
	// printf("|%04.2i|\n", 42);// == |  42|

	// ft_printf("|%s|\n",b);
	// printf("|%s|\n", b);
	ft_printf("%%#X 42 ==  %#X\n", 42);
	ft_printf("%%X 42 ==  %X\n", 42);
	ft_printf("%%#o 0 ==  %#o\n", 0);
	ft_printf("%%o 0 ==  %o\n", 0);
	ft_printf("%%#o max ==  %#o\n", max);
	ft_printf("%%o max ==  %o\n", max);
	ft_printf("%%#o min ==  %#o\n", min);
	ft_printf("%%o min ==  %o\n", min);
	ft_printf("%%#X min ==  %#X\n", min);
	ft_printf("%%X min ==  %X\n", min);
	ft_printf("%%#X max ==  %#X\n", max);
	ft_printf("%%X max ==  %X\n", max);
	printf("-------------------------------\n");
	printf("%%#X 42 ==  %#X\n", 42);
	printf("%%X 42 ==  %X\n", 42);
	printf("%%#o 0 ==  %#o\n", 0);
	printf("%%o 0 ==  %o\n", 0);
	printf("%%#o max ==  %#o\n", max);
	printf("%%o max ==  %o\n", max);
	printf("%%#o min ==  %#o\n", min);
	printf("%%o min ==  %o\n", min);
	printf("%%#X min ==  %#X\n", min);
	printf("%%X min ==  %X\n", min);
	printf("%%#X max ==  %#X\n", max);
	printf("%%X max ==  %X\n", max);
	return (0);
}
// int main(void)
// {
// 	//int a = 10000;
	

// 	//ft_printf("%33.46hhi\n", a);

// 	printf("%33.46hhi\n", (signed char)-431123122342323123);
// 	ft_printf("%33.46hhi\n", (signed char)-431123122342323123);
// 	//printf("%33.46hhi\n", (signed char)-43112312323123);
	
// 	// printf("|%d|\n", a);
// 	// printf("-: |%-d|\n", a);

// 	// printf("' '-: |% -d|\n", a);
// 	// printf("' ':|% d|\n", a);
	
// 	// printf("+: |%+d|\n", a);
// 	// printf("-+: |%-+d|\n", a);
	
// 	// printf("+7.2: |%+7.2d|\n", a);
	
// 	// printf("' '-7.6: |% -7.6d|\n", a);
// 	// printf("' '7.6: |% 7.6d|\n", a);

// 	// printf("' '-7.8: |% -7.8d|\n", a);
// 	// printf("--------------------\n");
// 	// printf("' '-9.5: |% -9.5d|\n", a);
// 	// printf("' '-9.6: |% -9.6d|\n", a);
// 	// printf("' '9.5: |% 9.5d|\n", a);
// 	// printf("' '9.6: |% 9.6d|\n", a);
// 	return (0);
// }
// int main(void)
// {
// 	ft_printf("|%#x|\n", 100);
// 	printf("|%#x|\n", 100);
// 	printf("--------------------\n");
// 	ft_printf("|%#X|\n", 100);
// 	printf("|%#X|\n", 100);
// 	printf("--------------------\n");
// 	ft_printf("|%#o|\n", 100);
// 	printf("|%#o|\n", 100);
// 	printf("--------------------\n");
// 	ft_printf("|%o|\n", 100);
// 	printf("|%o|\n", 100);
// 	printf("--------------------\n");
// 	ft_printf("|%X|\n", 100);
// 	printf("|%X|\n", 100);
// 	// ft_printf("|%5.3s|\n", "LYDI");
// 	// printf("|%5.3s|\n", "LYDI");
// 	// printf("|%-2.6s|\n", "LYDI");
// 	// ft_printf("|%-2.6s|\n", "LYDI");
// 	// printf("-------------------------\n");

// 	// ft_printf("|%10.4s|\n", "This is a test to see what will happen");
// 	// printf("|%10.4s|\n", "This is a test to see what will happen");
// 	// ft_printf("|%10.11s|\n", "This is a test to see what will happen");
// 	// printf("|%10.11s|\n", "This is a test to see what will happen");
// 	// printf("\n");
// 	// ft_printf("|%-10.4s|\n", "This is a test to see what will happen");
// 	// printf("|%-10.4s|\n", "This is a test to see what will happen");
// 	// ft_printf("|%-10.11s|\n", "This is a test to see what will happen");
// 	// printf("|%-10.11s|\n", "This is a test to see what will happen");
// 	// printf("-------------------------\n");
// 	// ft_printf("|%-20.20s|\n", "This is a test to see what will happen");
// 	// printf("|%-20.20s|\n", "This is a test to see what will happen");
// 	// printf("-------------------------\n");
// 	// ft_printf("|%20.20s|\n", "This is a test to see what will happen");
// 	// printf("|%20.20s|\n", "This is a test to see what will happen");
// 	return (0);
// }
// int main(void)
// {
// 	// ft_printf("|%5.3s|\n", "LYDI");
// 	// printf("|%5.3s|\n", "LYDI");
// 	// printf("|%-2.6s|\n", "LYDI");
// 	// ft_printf("|%-2.6s|\n", "LYDI");


// 	ft_printf("|%10.50s|\n", "This is a test to see what will happen");
// 	printf("|%10.50s|\n", "This is a test to see what will happen");
// 	return (0);
// }
// int main(void)
// {
// 	ft_printf("%x\n", 100);
// 	printf("%x\n", 100);
//
// 	ft_printf("%X\n", 100);
// 	printf("%X\n", 100);
//	
//	ft_printf("%#X\n", 100);
// 	printf("%#X\n", 100);
//	
// 	ft_printf("%#x\n", 100);
// 	printf("%#x\n", 100);
// }
//   int main(void)
//   {
//     uintmax_t a = 2147483647;
//     ft_printf("|%x|\n", -10);
//  	printf("|%x|\n", -10);

//  	ft_printf("|%x|\n", 10);
//  	printf("|%x|\n", 10);

// 	printf("x and #\n");
// 	ft_printf("|%#x|\n", (unsigned int)a);
// 	printf("|%#x|\n", (unsigned int)a);

// 	ft_printf("|%x|\n", (unsigned int)a);
// 	printf("|%x|\n", (unsigned int)a);

// 	ft_printf("|%5.3s|\n", "LYDI");
// 	printf("|%5.3s|\n", "LYDI");
// 	printf("|%-2.6s|\n", "LYDI");
// 	ft_printf("|%-2.6s|\n", "LYDI");
	
// 	//printf("|%20.*s|\n", 4,"This is a test");


// 	// 	ft_printf("|%15X|\n", -100);
// 	// 	printfw

// 	return (0);
//   }

// ft_printf("|%#15o|\n", -100);
// 	printf("|%#15o|\n", -100);


// ft_printf("%04i\n", 42);// == |0042|
// printf("%04i\n", 42);// == |0042|
// ft_printf("%05i\n", 42);// == |00042|
// printf("%05i\n", 42);// == |00042|
// ft_printf("%0i\n", 42);// == |42|
// printf("%0i\n", 42);// == |42|
// ft_printf("%0d\n", 0000042);// == |34|
// printf("%0d\n", 0000042);// == |34|
// 	//ft_printf("|%#15X|\n", -100);
// 	//printf("|%#15X|\n", -100);
//  }
// ft_printf("%04i\n", 42);// == |0042|
// printf("%04i\n", 42);// == |0042|
// ft_printf("%05i\n", 42);// == |00042|
// printf("%05i\n", 42);// == |00042|
// ft_printf("%0i\n", 42);// == |42|
// printf("%0i\n", 42);// == |42|
// ft_printf("%0d\n", 0000042);// == |34|
// printf("%0d\n", 0000042);// == |34|

// ft_printf("%04i\n", 42);// == |0042|
// ft_printf("%05i\n", 42);// == |00042|
// ft_printf("%0i\n", 42);// == |42|
// ft_printf("%0d\n", 0000042);// == |34|

// 	 ft_printf("%d %s %d %s %d\n",42, "Bla", 1001, "Moo",-8000);
// 	 printf("%d %s %d %s %d\n",42, "Bla", 1001, "Moo",-8000);
// 	ft_printf("%+i\n", 42);// == +42
// 	printf("%+i\n", 42);// == +42
	
// 	ft_printf("%+d\n", 42);// == +2147483647
// 	printf("%+d\n", 42);// == +2147483647
	
// 	ft_printf("%+04d\n", 42);// == +042
// 	printf("%+04d\n", 42);// == +042

// 	ft_printf("|%-4d|\n", 42);// == |42  |
// 	printf("|%-4d|\n", 42);// == |42  |
// 	ft_printf("|%-5d|\n", -42);// == |-42  |
// 	printf("|%-5d|\n", -42);// == |-42  |
// 	ft_printf("|%-4i|\n", 42);// == |42  |
// 	printf("|%-4i|\n", 42);// == |42  |


//  	// ft_printf("%d%% %s %p",a,d, &a);
//  	// printf("\n");
//  	// printf("%d%% %s %p",a,d, &a);
//  	// printf("|% 4.5i|\n", 42);// == | 00042|
//  	// ft_printf("|% 4.5i|\n", 42);// == | 00042|

//  	// printf("|% 4.6i|\n", 42);// == | 00042|
//  	// ft_printf("|% 4.6i|\n", 42);// == | 00042|

//  	// printf("|% 4.7i|\n", 42);// == | 00042|
//  	// ft_printf("|% 4.7i|\n", 42);// == | 00042
//  	// printf("\n");
//  	// printf("|% 5.4i|\n", 42);// == | 00042|
//  	// ft_printf("|% 5.4i|\n", 42);// == | 00042|

//  	// printf("|% 6.4i|\n", 42);// == | 00042|
//  	// ft_printf("|% 6.4i|\n", 42);// == | 00042|

//  	// printf(" 7 4 i\n");
//  	// printf("|% 7.4i|\n", 42);// == | 00042|
//  	// ft_printf("|% 7.4i|\n", 42);// == | 00042|

//  	// printf("Problem Right here:\n");
//  	// printf("|% 7.4d|\n", -42);
//  	// ft_printf("|% 7.4d|\n", -42);
//  	// printf("|% 7.4i|\n", -42);
//  	// ft_printf("|% 7.4i|\n", -42);


//  	// printf("|% 7.4d|\n", 42);
//  	// ft_printf("|% 7.4d|\n",42);

//  	// printf("7 4 d\n");
//  	// printf("|%7.4d|\n", 42);
//  	// ft_printf("|%7.4d|\n",42);
//  	// printf("\n");
//  	// printf("|% 4.7d|\n", 42);
//  	// ft_printf("|% 4.7d|\n",42);

//  	// printf("|%+4.7d|\n", 42);
//  	// ft_printf("|%+4.7d|\n",42);
//  	// printf("|%+4.7d|\n", -42);
//  	// ft_printf("|%+4.7d|\n",-42);
//  	// printf("\n");
//  	return (0);
//  }
// int main(void)
// {
// 	printf("x with #\n");
// 	ft_printf("%#x", 10000);
// 	printf("\n");
// 	printf("%#x\n", 10000);

// 	printf("x with no #\n");
// 	ft_printf("%x", 10000);
// 	printf("\n");
// 	printf("%x\n", 10000);

// 	printf("X with #\n");
// 	ft_printf("%#X", 10000);
// 	printf("\n");
// 	printf("%#X\n", 10000);


// 	printf("X with no #\n");
// 	ft_printf("%X", 10000);
// 	printf("\n");
// 	printf("%X\n", 10000);

// 	printf("o with #\n");
// 	ft_printf("%#o", 10000);
// 	printf("\n");
// 	printf("%#o\n", 10000);

// 	printf("o with no #\n");
// 	ft_printf("%o", 10000);
// 	printf("\n");
// 	printf("%o\n", 10000);
// 	return (0);

// }
// int main (void)
// {

// // int c =2;
// // int *ptr2 = &c;

// // ft_printf("%p\n", ptr2);
// // printf("%p\n", ptr2);
// // 	wchar_t a = L'à';
// // 	wchar_t *b = L"дддд";
// // 	ft_printf("%C", a);
// // 	printf("\n");
// // 	ft_printf("%S", b);
// 	//wchar_t l = L'à';
// 	wchar_t *a = L"àààà";
// 	wchar_t b = L'à';

// 	printf("Wide Char\n");
// 	ft_printf("%C\n", b);
// 	printf("%lc\n",b);
// 	printf("Wide Str\n");
// 	ft_printf("%S", a);
// 	printf("\n");
// 	printf("%ls\n", a);
// 	printf("Number Spacing 1: \n");
// 	printf("|%      i|\n", 42);
// 	ft_printf("|%      i|", 42);
// 	printf("\n");
// 	printf("Number Spacing 2: \n");
// 	printf("|% i|\n", -42);
// 	ft_printf("|% i|", -42);
// 	printf("\nPrecision Checking 1: \n");
// 	printf("|%-5.3s|\n","LYDI");
// 	ft_printf("|%-5.3s|","LYDI");
// 	printf("\nPrecision Checking 2: \n");
// 	printf("|% 4.5i|\n", 42);
// 	ft_printf("|% 4.5i|", 42);
// 	printf("\nPrecision Checking 3: \n");
// 	printf("|% 4.5d|\n", 42);
// 	ft_printf("|% 4.5d|", 42);
// 	return (0);
// }
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
