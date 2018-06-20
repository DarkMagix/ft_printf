#include "ft_printf.h"

void format_ptr(char *str, t_params *params)
{
    char *temp;
    size_t size_str;
    char *hex = "0";
    temp = ft_strnew(1);
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
	//free(temp);
    }
    else
    {
        hex = ft_strjoin(hex, "x");
        temp = ft_strjoin(hex, str);
        params->buff = temp;
	//free(temp);
    }
}

void format_hex(t_params *params)
{
    char *temp;
    int size;
    int i;

    i = 0;
    size = (int)ft_strlen(params->buff);
    size = (params->hash) ? size + 2 : size;
    temp = ft_strnew(size);
    if (params->specifier == 'X')
    {
        while (params->buff[i])
        {
            params->buff[i] = ft_toupper(params->buff[i]);
            i++;
        }
    }
    if(params->hash && params->specifier == 'x')
      ft_strcat(temp, "0x");
    else if(params->hash && params->specifier == 'X')
        ft_strcat(temp, "0X");
    
    ft_strcat(temp, params->buff);

    params->buff = temp;
    
	//free(temp);
}

// void format_str(t_params *params)
// {
//     int display_len;
//     int write_len;
//     int str_size;
//     char* write;
//     int k;

//     k = 0;
//     if (params->buff == NULL)
//     {
//         params->buff = "(null)";
//         return ;
//     }
//     str_size = ft_strlen(params->buff);
//     display_len = (params->wid_len < print_length(params)) ? 
//         print_length(params) : params->wid_len ;
//     write = ft_memalloc(display_len);
//     if (params->num_len == 0)
//         write_len = (params->num_len < str_size) ? str_size : params->num_len;
//     else    
//         write_len = (params->num_len < str_size) ? params->num_len : str_size;
//     justify_str(write, params, write_len, display_len);
//     params->buff = write;
//     free(write);

    
// }