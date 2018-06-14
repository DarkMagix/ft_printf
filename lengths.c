#include "ft_printf.h"

int print_length(t_params *params)
{
    int print_len;//print length
    int width; //params width length to show
    int str_size; //size of the string

    width = params->wid_len;
    str_size = ft_strlen(params->buff);
    print_len = (str_size > width) ? str_size : width;
    return (print_len);
}

void justify_str(char *write, t_params *params, int write_l, int display_l)
{
    int k;

    k = 0;
    if(params->justify)
    {  
        ft_strncat(write, params->buff, write_l);
        k = ft_strlen(write);
        while (k < display_l)
        {
            write[k] = ' ';
            k++;
        }
    }
    else
    {
        while (k < display_l - write_l)
        {
            write[k] = ' ';
            k++;
        }
        ft_strncat(write, params->buff, write_l);
    }
}