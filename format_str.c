#include "ft_printf.h"

void format_ptr(char *str, t_params *params)
{
    char *temp;
    size_t size_str;
    char *hex = "0";
    temp = 0;
    if(params->hash)
    {
        size_str = ft_strlen(str);
        if (params->specifier == 'X')
        {
            hex = ft_strjoin(hex, "X");
            temp = ft_strjoin(hex, str);
        }
        else if (params->specifier == 'x')
        {
            hex = ft_strjoin(hex, "x");
            temp = ft_strjoin(hex, str);
        }
        else if (params->specifier == 'o')
        {
            hex = ft_strjoin(hex, str);
            temp = hex;   
        }
        params->buff= temp;
    }
    else
    {
        
        hex = ft_strjoin(hex, "x");
        temp = ft_strjoin(hex, str);
        params->buff = temp;
    }

}

void format_hex(char *str, t_params *params)
{
    char *temp;
    char *hex;
    
    temp = ft_strnew(0);
    hex = ft_strnew(0);
    int i;
    i = 0;
    if(params->specifier == 'X')
    {
        while(str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'f')
                str[i] -= 32;
            i++;
        }
        if(params->hash)
            hex = ft_strjoin(hex, "0X");
    }
    else if(params->specifier == 'x')
    {
        if(params->hash)
            hex = ft_strjoin(hex, "0x");
        
    }
    temp = ft_strjoin(hex, str);
    params->buff = temp;
}