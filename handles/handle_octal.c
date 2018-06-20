#include "../ft_printf.h"

void prepare_octal(t_params *params)
{
    params->buff = ft_uitoa_base(params->u, 8);
    params->len = ft_strlen(params->buff);
    //printf("Length of Octal %d\n", params->len);
    if (params->hash && params->buff[0] != '0')
        params->zeroes++;
    if (params->num_len > params->len + params->zeroes)
        params->zeroes = params->num_len - params->len;
    if (params->justify)
        params->spaces = params->wid_len - (params->zeroes + params->len);
    else
        (params->pad) ? (params->zeroes += params->wid_len - (params->zeroes + params->len))
            : (params->spaces = params->wid_len - (params->zeroes + params->len));
}

void setup_octal(va_list list, t_params *params)
{
    if (params->specifier == 'O')
        params->modifer = MODI_l;
    uint_flags(list, params);
    prepare_octal(params);
    if (params->justify)
    {
        print_chars(params, '0', params->zeroes);
        print_nums(params);
        print_chars(params, ' ', params->spaces);
    }
    else
    {
        print_chars(params, ' ', params->spaces);
        print_chars(params, '0', params->zeroes);
        print_nums(params);
    }
    
}