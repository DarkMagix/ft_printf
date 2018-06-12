#include "ft_printf.h"

int print_ptr(va_list list, t_params *params)
{
    int i;
 
    i = 0;
    uintmax_t num;
    char *str;

 
    //    printf("%d", thing);
    num = va_arg(list, uintmax_t);
    str = ft_uitoa_base(num, 16);
    format_ptr(str, params);
    //    params->buff = str;
    //    printf("\nIn Print_Ptr\n");
    ft_putstr(params->buff);
     free(params->buff);
    free(str);
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

int print_octal(va_list list, t_params *params)
{
    uintmax_t num;
    char  *number;

    num = va_arg(list, uintmax_t);
    number = ft_uitoa_base(num, 8);
    params->buff = number;
    ft_putstr(params->buff);
    free(params->buff);
   // free(number);
    return (1);
}
