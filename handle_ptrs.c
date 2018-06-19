#include "ft_printf.h"

void setup_ptr(va_list list, t_params *params)
{
    params->u = va_arg(list, unsigned long int);
    params->buff = ft_uitoa_base(params->u, 16);
    params->inc += write(1, "0x", 2);
    params->inc += write(1, params->buff, ft_strlen(params->buff));
}