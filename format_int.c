/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:08:25 by mweir             #+#    #+#             */
/*   Updated: 2018/06/08 17:08:26 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	neg_justified(char *temp, char *str, t_params *params, int size)
{
	if (params->is_neg && !params->pad)
	{
		printf("\nIs Neg and No pad\n");
		ft_strcat(temp, "-");
		ft_strcat(temp, str);
		
		ft_add_pad(temp, params, size);
	}
	else if (params->is_neg && params->pad)
	{
		printf("\nis neg and pad\n");
		ft_add_pad(temp, params, size);
		ft_strcat(temp, "-");
		ft_strcat(temp, str);
	}
}

void	pos_justified(char *temp, char *str, t_params *params, int size)
{
	if (!params->is_neg && !params->pad)
	{
		if (params->plus_neg)
			ft_strcat(temp, "+");
		ft_strcat(temp, str);
		ft_add_pad(temp, params, size);
	}
	else if (!params->is_neg && params->pad)
	{
		ft_add_pad(temp, params, size);
		if (params->plus_neg)
			ft_strcat(temp, "+");
		ft_strcat(temp, str);
	}
}

void	neg_no_justified(char *temp, char *str, t_params *params, int size)
{
	if (params->is_neg && params->pad && params->spaced)
	{
		ft_add_pad(temp, params, size);
		ft_strcat(temp, str);
	}
	else if (params->is_neg && params->pad == true && !params->spaced)
	{
	//	printf("\nIs Neg, Pad is True, Spaced is Not True\n");
		
		ft_add_pad(temp, params, size);
		ft_strcat(temp, str);
	}
	else if (params->is_neg && params->pad == false)
	{
		
		ft_add_pad(temp, params, size);
		ft_strcat(temp, "-");
		ft_strcat(temp, str);
	}
}

void	pos_no_justified(char *temp, char *str, t_params *params, int size)
{
	if (!params->is_neg && params->pad)
	{
		if (params->plus_neg)
			ft_strcat(temp, "+");
		ft_add_pad(temp, params, size);
		ft_strcat(temp, str);
	}
	else if (!params->is_neg && !params->pad)
	{
		ft_add_pad(temp, params, size);
		if (params->plus_neg)
			ft_strcat(temp, "+");
		ft_strcat(temp, str);
	}
}
