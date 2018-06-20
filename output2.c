#include "ft_printf.h"

int print_wchar(va_list list, t_params *params)
{
    int i;

    i = 0;
    wchar_t let;
    
    let = va_arg(list, wchar_t);
    params = NULL;
    ft_wputchar(let);
    return (i);
}

int print_wstr(va_list list, t_params *params)
{
    ft_putwstr(list, params);
    return (1);
}

int print_octal(va_list list, t_params *params)
{
    setup_octal(list, params);

    return (params->inc);
}
