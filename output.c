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
int print_integer(va_list list, t_params *params)
{
    char sign;
    int num;
    sign = params->plus_neg;
    int length;
    
    if(params->p_wildcard)
    {
        length = va_arg(list, int);
        params->num_len = length;
    }
    if(params->justify)
    {
        printf("Justified\n");
        num = va_arg(list, int);
        if (params->plus_neg)
        {
            if (num >=0)
                ft_putchar('+');
        }
        ft_putnbr(num);
        
        while(params->num_len > 0)
        {
            ft_putchar(' ');
            params->num_len--;
        }
    }
    else
    {
        printf("Not JUstified\n");
        
        while(params->num_len > 0)
        {
            ft_putchar(' ');
            params->num_len--;
        }
        ft_putnbr(va_arg(list, int));
    }
    return (1);
}
int print_float(va_list list)
{
    ft_putnbr(va_arg(list, int));
    return (1);
}
int print_hex(unsigned int n, int flag)
{
    char *hex="0123456789abcdef";
   // printf("%u", n);
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