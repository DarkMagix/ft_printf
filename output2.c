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
    params->buff = str;
    ft_putstr(params->buff);
    free(params->buff);
    return (i);
}
