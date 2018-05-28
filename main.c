#include "ft_printf.h"

void ft_parse(int flag, va_list arg)
{       
        if (flag == 's')
        {
                print_str(arg);
        }
        else if (flag == 'd')
        {
               print_integer(arg);
        }
        else if (flag == 'c')
        {
                print_char(arg);
        }
        else if (flag == '%')
                ft_putchar('%');
        else if (flag == 'x' || flag == 'X')
                print_hex(va_arg(arg, unsigned int),flag);
}

void ft_printf(char *frmt, ...)
{
        char *ptr;
        va_list args;
        va_start(args, frmt);       
        ptr = frmt;
        while (*ptr != '\0')
        {
                if (*ptr == '%')
                    ft_parse(*(++ptr), args);
                else
                        ft_putchar(*ptr);
                ptr++;
        }
        va_end(args);
}

int main(void)
{
        ft_printf("%s %X", "Test", 99999);
        return (0);
}