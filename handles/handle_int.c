#include "../ft_printf.h"

static void prepare_int(t_params *params)
{
    params->buff = ft_itoa_base(params->i, 10);
    params->len = ft_strlen(params->buff);
    if (params->num_len > params->len)
        params->zeroes = params->num_len - params->len;
    if (params->wid_len > params->len + params->zeroes)
        params->spaces = params->wid_len -(params->len + params->zeroes);
    if (params->plus_neg && !(IS_NEG(params->i)))
        params->sign = '+';
    if (params->plus_neg && params->pad)
        params->spaces--;
    if (params->spaced && !(IS_NEG(params->i)) && params->spaces == 0)
        params->spaces++;
}

void setup_int(va_list list, t_params *params)
{
    if (params->specifier == 'D')
        params->modifer = MODI_ll;
    sint_flags(list, params);
    prepare_int(params);
    if (params->justify && params->pad)
        params->pad = false;
 
    //if (!params->justify)
   // {
     //  printf("Width: %d", params->num_len);
       //printf("Spaces %d\n", params->spaces);
    
    if(!params->justify)
    {
        if (params->sign && !params->pad)
        {
            ft_putchar(params->sign);
             params->inc++;
        }
        print_chars(params, ' ', params->spaces);
        print_chars(params, '0', params->zeroes);
        print_nums(params);
    }
    else
    {
        if (params->sign)
        {
            ft_putchar(params->sign);
            params->inc++;
        }
        print_chars(params, '0', params->zeroes);
        print_nums(params);
        //printf("Spaces %d\n", params->spaces);
        print_chars(params, ' ', params->spaces);
        
    }
   // }
    // else
    // {
    //     if (params->sign && !params->pad && params->inc++)
    //         ft_putchar(params->sign);
    //     print_chars(params, '0', params->zeroes);
    //     print_nums(params);
    //     print_chars(params, ' ', params->spaces);
    // }
 
}