/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:32:36 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:32:37 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_wchar(va_list list, t_params *params)
{
	if (params->num_len == 0 && params->wid_len == 0)
		params->inc++;
	else if (params->wid_len > 0)
	{
		while (params->wid_len-- > 1)
			params->inc += write(1, " ", 1);
		params->inc++;
	}
	params->inc += (params->num_len > 0) ? 1 : 0;
	ft_putchar(va_arg(list, wint_t));
	return (1);
}

int		print_wstr(va_list list, t_params *params)
{
	ft_putwstr(list, params);
	return (1);
}

int		print_octal(va_list list, t_params *params, int flag)
{
	params->modifer = (flag == 'O') ? MODI_l : params->modifer;
	setup_octal(list, params);
	return (params->inc);
}

void	ft_print_pers(t_params *params)
{
	ft_putchar('%');
	params->inc++;
}
