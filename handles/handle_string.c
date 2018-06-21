/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:33:14 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:33:15 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void get_printlen(t_params *params, char *s)
{
    if (!s)
    {
        params->wid_len = 0;
        return ;
    }
    if(params->wid_len > ft_strlen(s) + params->num_len)
        params->wid_len -= ft_strlen(s);
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
void print_words(t_params *params, char *s, int i)
{
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
    if(params->num_len == 0 && params->has_num_len == true)
    {
        while(params->wid_len--)
            write(1, " ", 1);
        return ;
    }
    get_printlen(params, s);
    if(!params->justify)
        print_spaces(params);

    print_words(params, s, i);
    print_spaces(params);
}

void ft_print_pers(t_params *params)
{
    ft_putchar('%');
	params->inc++;
}
