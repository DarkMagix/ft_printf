/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:32:23 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:32:26 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_length(t_params *params)
{
	int print_len;
	int width;
	int str_size;

	width = params->num_len;
	str_size = ft_strlen(params->buff);
	print_len = (str_size > width) ? width : str_size;
	return (print_len);
}

void	justify_str(char *write, t_params *params, int write_l, int display_l)
{
	int k;

	k = 0;
	if (params->justify)
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
