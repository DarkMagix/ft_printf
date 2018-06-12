#include "ft_printf.h"

int print_ptr(va_list list, t_params *params)
{
    int i;
    int thing;
    i = 0;
    uintmax_t num;
    char *str;

    thing = params->modifer;
    num = va_arg(list, uintmax_t);
    str = ft_uitoa_base(num, 16);
    params->buff = str;
    ft_putstr(params->buff);
    free(params->buff);
    return (i);
}

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
    int i;

    i = 0;
    wchar_t* str;
    
    str = va_arg(list, wchar_t*);
    params = NULL;
    ft_wputstr(str);
    return (i);
}