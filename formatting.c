#include "ft_printf.h"
void ft_padstr(char *str, t_params *params, int size)
{
    while(size-- > 0)
    {
        if(params->pad)
            ft_strcat(str, "0");
        else
            ft_strcat(str, " ");
        }
}
void ft_signstr(char *str, t_params *params)
{
    if (params->plus_neg)
        ft_strcat(str, "+");
   
}
void ft_format_int(t_params *params)
{
    char *temp;
    
    int size;
    temp = ft_strnew(1);
    size = params->wid_len - (int)ft_strlen(params->buff);
    if(!params->justify)
    {
        ft_padstr(temp, params, size);
        ft_signstr(temp, params);
        ft_strcat(temp, params->buff);
    }
    else
    {
        ft_signstr(temp, params);
        ft_strcat(temp, params->buff);   
        ft_padstr(temp, params, size);
    }
    params->buff = temp;
}
