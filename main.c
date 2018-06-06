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
        ft_printf("(%08d)(%08d)", 21474,3);
        printf("\n(%08d)(%08d)", 21474,3);
      //  ft_printf("%-8d     %-d", 21474,3);
       // printf("\n<%-3.8u>     %-u", 21474,3);
        
        
        return (0);
}