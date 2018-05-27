#include "ft_printf.h"

void ft_parse(int flag, va_list arg)
{       
        char *s;
        int int_num;
        if (flag == 's')
        {
                s = va_arg(arg, char *);
                ft_putstr(s);
        }
        else if (flag == 'd')
        {
                int_num = va_arg(arg, int);
                ft_putnbr(int_num);
        }
        else if (flag == '%')
                ft_putchar('%');
        

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
                {
                    ft_parse(*(++ptr), args);
                }
                else if (*ptr ==' ')
                        ft_putchar(' ');
                ptr++;
        }
        va_end(args);
}

int main(void)
{
        ft_printf("%s %d", "Test", 1239);
        return (0);
}