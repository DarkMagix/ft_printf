/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:06:38 by mweir             #+#    #+#             */
/*   Updated: 2018/06/08 17:06:44 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_chars(t_params *params, char c, int n)
{
    params->inc += n;
    while (n > 0)
    {
        ft_putchar(c);
        n--;
    }
}

void print_nums(t_params *params)
{
    write(1, params->buff, params->len);
    params->inc += params->len;
}


