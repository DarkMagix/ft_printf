/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:33:09 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:33:09 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void setup_ptr(va_list list, t_params *params)
{
    params->u = va_arg(list, unsigned long int);
    params->buff = ft_uitoa_base(params->u, 16);
    params->inc += write(1, "0x", 2);
    params->inc += write(1, params->buff, ft_strlen(params->buff));
}
