#include "ft_printf.h"


int print_char(va_list list)
{
    ft_putchar(va_arg(list, int));
    return (1);
}

int print_str(va_list list)
{
    ft_putstr(va_arg(list, char*));
    return (1);
}

int print_integer(va_list list)
{
        ft_putnbr(va_arg(list, int));
        return (1);
}
int print_hex(unsigned int n, int flag)
{
    char *hex="0123456789abcdef";
    if (n >= 16)
        return (print_hex(n / 16, flag) + print_hex(n % 16, flag));
    else
    {
        if (flag == 'x')
            ft_putchar(hex[n]);
        else
            ft_putchar(ft_toupper(hex[n]));
    }
    return (1);
}