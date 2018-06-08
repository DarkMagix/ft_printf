#include "ft_printf.h"

void ft_add_pad(char *str, t_params *params, int size)
{
    if (params->is_neg || params->plus_neg)
        size--;
    while (size > 0)
    {
        if (params->pad)
            ft_strcat(str, "0");
        else
            ft_strcat(str, " ");
        size--;
    }
}

void ft_padstr(char *str, t_params *params, int size)
{
    char *temp;
    temp = ft_strnew(1);
    if (params->justify)
    {
        //	ft_strcat(temp, str);
        if (params->is_neg && !params->pad)
        {
            ft_strcat(temp, "-");
            ft_strcat(temp, str);
            ft_add_pad(temp, params, size);
        }
        else if (params->is_neg && params->pad)
        {
            ft_add_pad(temp, params, size);
            ft_strcat(temp, "-");
            ft_strcat(temp, str);
        }
        else if (!params->is_neg && !params->pad)
        {
            if (params->plus_neg)
                ft_strcat(temp, "+");
            ft_strcat(temp, str);
            ft_add_pad(temp, params, size);
        }
        else if (!params->is_neg && params->pad)
        {
            ft_add_pad(temp, params, size);
            if (params->plus_neg)
                ft_strcat(temp, "+");
            ft_strcat(temp, str);
        }
    }
   // free(temp);
    else
      {
        if(params->is_neg && params->pad)
        {
            ft_strcat(temp, "-");
            ft_add_pad(temp, params, size);
        }
        else if (params->is_neg && !params->pad)
        {
            ft_add_pad(temp, params, size);
            ft_strcat(temp, "-");
        }
        else if(!params->is_neg && params->pad)
        {
            if(params->plus_neg)
                ft_strcat(temp, "+");
            ft_add_pad(temp, params, size);
        }
        else if (!params->is_neg && !params->pad)
        {
            ft_add_pad(temp, params, size);
            if(params->plus_neg)
                ft_strcat(temp, "+");
        }
        ft_strcat(temp, str);
      }
    params->buff = temp;
}
void ft_signstr(char *str, t_params *params)
{
    if (params->is_neg)
        ft_strcat(str, "-");
    else if (params->plus_neg)
        ft_strcat(str, "+");
}
int ft_find_length(int width, int str_len)
{
   // printf("\nW: %d Str Len: %d\n", width, str_len);
    if (width > str_len)
        return (width - str_len);
    else
        return (0);
}

void ft_format_int(t_params *params)
{
    char *temp;

    int size;
    temp = ft_strnew(((int)ft_strlen(params->buff)));

    //ft_signstr(temp, params);
   
    size = ft_find_length(params->wid_len, (int)ft_strlen(params->buff));
  
    ft_strcat(temp, params->buff);
    ft_padstr(temp, params, size);
    free(temp);
}
