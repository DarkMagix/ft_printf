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
int print_sint(va_list list, t_params *params)
{
    long long int num;
    num = sint_flags(list, params);
    params->buff = ft_strdup(ft_itoa_base(num, 10));
    ft_putstr(params->buff);
    

    return (1);
}

int print_uint(va_list list, t_params *params)
{
  int long long num;
  num = uint_flags(list, params);
  params->buff = ft_strdup(ft_uitoa_base(num, 10));
  ft_putendl(params->buff);
  return (1);
}

int print_integer(va_list list, t_params *params)
{
    int num;
    int length;
    length = 0;
    if(params->p_wildcard)
    {
        length = va_arg(list, int);
        params->num_len = length;
    }
    if(params->justify)
    {
        num = va_arg(list, int);
        if (params->plus_neg)
        {
            if (num >=0)
                ft_putchar('+');
        }
        ft_putnbr(num);   
        while(params->num_len > 0)
        {
            ft_putchar((params->pad == true) ? '0' : ' ');
            params->num_len--;
        }
    }
    else
    {
        while(params->num_len > 0)
        {
            ft_putchar((params->pad == true) ? '0' : ' ');
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
