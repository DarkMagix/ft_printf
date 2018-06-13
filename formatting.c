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


void	ft_add_pad(char *str, t_params *params, int size)
{
  //  printf("\nSize: %d\n", size);
	if (params->is_neg || params->plus_neg)
		size--;
	if (params->spaced && !params->is_neg && size <= 0)
	{
		  ft_strcat(str, " ");
	}
	while (size > 0)
	{
		if (params->pad)
			ft_strcat(str, "0");
		else
			ft_strcat(str, " ");
		size--;
	}
}

void	ft_padstr(char *str, t_params *params, int size)
{
	char *temp;

	temp = ft_strnew((int)ft_strlen(params->buff));
	if (params->justify)
	{
		neg_justified(temp, str, params, size);
		pos_justified(temp, str, params, size);
	}
	else
	{
		neg_no_justified(temp, str, params, size);
		pos_no_justified(temp, str, params, size);
	}
	params->buff = ft_strdup(temp);
	free(temp);
}

void	ft_signstr(char *str, t_params *params)
{
	if (params->is_neg)
		ft_strcat(str, "-");
	else if (params->plus_neg)
		ft_strcat(str, "+");
}

int		ft_find_length(int width, int str_len)
{
	if (width > str_len)
		return (width - str_len);
	else
		return (0);
}

void	ft_format_int(t_params *params)
{
	char	*temp;
	int		size;

	temp = ft_strnew(((int)ft_strlen(params->buff)));
	size = ft_find_length(params->wid_len, (int)ft_strlen(params->buff));
	ft_strcat(temp, params->buff);
	ft_padstr(temp, params, size);
	free(temp);
}
