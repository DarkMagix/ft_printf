#include "ft_printf.h"

void to_upper(t_params *params)
{
    int i;

    i = -1;
    while (params->buff[++i])
        if (ft_isalpha(params->buff[i]))
            params->buff[i] -= 32;
}

void prepare_hex(t_params *params)
{
    params->buff = ft_uitoa_base(params->u, 16);
    
    if (params->specifier == 'X')
        to_upper(params);
    params->len = ft_strlen(params->buff);
    if (params->num_len > params->len)
        params->zeroes = params->num_len - params->len;
    if (params->wid_len > params->len + params->zeroes)
        params->spaces = params->num_len - (params->len + params->zeroes);
    
}

void setup_hex(va_list list, t_params *params)
{
    uint_flags(list, params);
    prepare_hex(params);
    if (params->justify)
    {
        if (params->hash)
            params->inc += (params->specifier == 'x') ? (write(1, "0x", 2))
                : (write(1, "0X", 2));
        print_chars(params, '0', params->zeroes);
        print_nums(params);
        params->spaces > 0 ? print_chars(params, ' ', params->spaces) : 0;
    }
    else
    {
        (params->zeroes > 0) ? (print_chars(params, '0', params->spaces))
            : (print_chars(params, ' ', params->spaces));
        if (params->hash)
            params->inc += (params->specifier == 'x') ? (write(1, "0x", 2))
                : (write(1, "0X", 2));
        print_chars(params, '0', params->zeroes);
        print_nums(params);
    }
}