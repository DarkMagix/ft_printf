#include "../ft_printf.h"

void get_printlen(t_params *params, char *s)
{
    if (!s)
    {
        params->wid_len = 0;
        return ;
    }
    if(params->wid_len > ft_strlen(s) + params->num_len)
    {
        params->wid_len -= ft_strlen(s);
    }
    else
        params->wid_len = (params->wid_len > params->num_len) 
        ? params->wid_len - params->num_len : params->wid_len - ft_strlen(s);
}

void print_spaces(t_params *params)
{
    if (params->wid_len > 0)
    {
        while(params->wid_len)
        {
	  write(1, " ", 1);
	  params->wid_len -=1;
	  params->inc++;
        }
    }
}

void ft_putstring(va_list list, t_params *params)
{
    char *s;
    int i;

    i = -1;
    s = va_arg(list, char*);
    if (!s)
    {
        write(1, "(null)", 6);
        return ;
    }
    get_printlen(params, s);
    if(!params->justify)
      print_spaces(params);
    while(s[++i])
    {
        if(params->num_len && params->num_len < ft_strlen(s))
        {
            while(params->num_len--)
            {
                ft_putchar(s[i++]);
                params->inc++;
            }
            break;
        }
        ft_putchar(s[i]);
        params->inc++;
    }
   print_spaces(params);
   //   free(params->buff);
}
