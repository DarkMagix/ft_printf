#include "ft_printf.h"


void ft_wstrlen(t_params *params)
{
    size_t i;

    i = -1;
    while(params->w_s[++i] != L'\0')
        params->len++;

}

void print_wst(t_params *params)
{
    int i;

    i = -1;

    while (params->w_s[++i] != L'\0' && i <= params->spaces) 
    {
       // printf("%d", i);
        ft_wputchar(params->w_s[i]);
        params->inc++;
        
    }
}

void print_string(t_params *params)
{
    params->spaces = (params->num_len != -1 && params->num_len < params->len)
        ? (params->num_len) : (params->len);
  //  printf("Spaces %d\n", params->spaces);
  //  printf("Num Len %d and Wid Len %d\n", params->num_len, params->wid_len);
    //printf("Spaces %d\n", params->spaces);
    print_wst(params);
}

void print_spaces(t_params *params)
{
    params->spaces = (params->num_len >= 0 && params->num_len < params->len)
    ? (params->wid_len - params->len) : (params->wid_len - params->num_len);
    while (params->spaces > 0)
    {
        params->inc += write(1, "          ",
            (params->spaces >= 10) ? 10 : params->spaces);
        params->spaces -= (params->spaces >= 10) ? 10 : params->spaces;

    }   
}

void setup_wstring(va_list list, t_params *params)
{
    params->w_s = va_arg(list, wchar_t*);
    if (!params->w_s && (params->inc = write(1, "(null)", 6)))
        return ;
    ft_wstrlen(params);
    
  // printf("String Length: %d", params->len);
 //   printf("Str Len: %d\n", params->len);
    if (params->justify)
    {
        print_string(params);
        print_spaces(params);
    }
    else
    {
        print_spaces(params);
        print_string(params);
    }
}