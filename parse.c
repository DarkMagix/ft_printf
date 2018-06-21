/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:07:23 by mweir             #+#    #+#             */
/*   Updated: 2018/06/08 17:07:25 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_data(t_params *params, char *format, va_list list)
{
	int i;

	i = 0;
	i += parse_flags(&format[i], params);
	i += parse_width(&format[i], params, list);
	i += parse_precision(&format[i], params, list);
	i += parse_length(&format[i], params);
	return (i);
}
