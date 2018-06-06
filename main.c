#include "ft_printf.h"

void ft_parse(int flag, va_list arg, t_params *params)
{       
        if (flag == 's')
        {
                print_str(arg);
        }
        else if (flag == 'd')
        {
               print_sint(arg, params);
        }
        else if (flag == 'u')
        {
                print_uint(arg, params);
        }
        else if (flag == 'c')
        {
                print_char(arg);
        }
        else if (flag == '%')
                ft_putchar('%');
        else if (flag == 'x' || flag == 'X')
        {
                print_hex(va_arg(arg, unsigned int), flag);
        }
	else if(flag == 'u')
		print_uint(arg, params);
	else if (flag == 'i')
	  print_sint(arg, params);
}

void ft_printf(const char *frmt, ...)
{
        va_list args;
        t_params *params;
        params = ft_memalloc(sizeof(t_params));
        if(frmt)
        {
                va_start(args, frmt);       
                parse_specifier(frmt, args, params);
                va_end(args);
        }
}

int main(void)
{
  
  //  printf("Size of 10 is %d\n", (int)sizeof(10));
  //  printf("Size of int is %d\n", (int)sizeof(n2));
  //  printf("Size of intmax_t is %d\n", (int)sizeof(n));
  short b = 32800;
  ft_printf("%d\n", (int)b);
  ft_printf("%-9hd\n", b);
  ft_printf("%09hd\n", b);
  ft_printf("%+9hd\n", b);
  ft_printf("%-+9hd\n", b);
  printf("-----------------\n");
  printf("%d\n", (int)b);
  printf("%-9hd\n", b);
  printf("%09hd\n", b);
  printf("%+9hd\n", b);
  printf("%-+9hd\n", b);
       // ft_printf("%d", -2);
        
      //  ft_printf("%-8d     %-d", 21474,3);
       // printf("\n<%-3.8u>     %-u", 21474,3);
        
        
        return (0);
}
