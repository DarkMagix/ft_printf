#include "../ft_printf.h"

static void prepare_int(t_params *params)
{
    params->buff = ft_itoa_base(params->i, 10);
    params->len = ft_strlen(params->buff);
    //printf("Spaces: %d\n", params->spaces);
    //#.0 = wid, 0.# = num
    //pad == 0 flag
    //plus_neg = + flag
    //space flag = spaced flag
    //3 > 2 then 3 - 2
    if (params->wid_len > params->len && !params->justify && params->num_len)
        params->zeroes = params->wid_len - params->len;
        //printf("Wid Len %d > Str Len %d && Justify && Num Len %d\n", params->wid_len, params->len, !params->justify, !params->num_len);
    if (params->wid_len > params->len && !params->justify && !params->num_len)
    {
        //printf("Zeroes %d\n", params->wid_len - params->len);
        if (!params->pad)
            params->spaces = params->wid_len - params->len;
        if (params->pad)
            params->zeroes = params->wid_len - params->len;
       // printf("Spaces %d Zeroes %d", params->spaces, params->zeroes);
        //params->spaces = params->zeroes;
        //params->zeroes = 0;
    }
   // printf("Zeroes: %d", params->zeroes);
    if (params->plus_neg)
        params->zeroes--;
    //printf("0's %d", params->zeroes);
    if (params->wid_len > params->len + params->zeroes)// 3 > 2 + 1
        params->spaces = params->wid_len -(params->len + params->zeroes);
    if (params->plus_neg && !(IS_NEG(params->i)))
        params->sign = '+';
    if (params->plus_neg && params->pad)
        params->spaces-=2;
    if (params->spaced && !(IS_NEG(params->i)) && params->spaces == 0)
        params->spaces++;
 //   printf("Spaces: %d\n", params->spaces);
    // if (params->pad)
    // {
    //     params->zeroes = params->wid_len - ft_strlen(params->buff);
    // }
}

void setup_int(va_list list, t_params *params)
{
   
    if (params->specifier == 'D')
        params->modifer = MODI_ll;
    sint_flags(list, params);
    prepare_int(params);
     //printf("\nZeros is %d\n", params->zeroes);
    if (params->justify && params->pad)
        params->pad = false;
    //printf("Zeroes: %d Spaces: %d\n", params->zeroes, params->spaces);
    if(!params->justify)
    {
        if (params->sign)
        {
            ft_putchar(params->sign);
             params->inc++;
        }
        print_chars(params, ' ', params->spaces);
        print_chars(params, '0', params->zeroes);
        print_nums(params);
    }
    else //Justified
    {
        // write(1,"here",4);
        if (params->sign)
        {
            
            ft_putchar(params->sign);
            params->inc++;
        }
        //params->zeroes = 0;
        //print_chars(params, '0', params->zeroes);
        print_nums(params);
        //printf("Spaces %d\n", params->spaces);
        print_chars(params, ' ', params->spaces);
	//	free(params->buff);
    }
    free(params->buff);
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
