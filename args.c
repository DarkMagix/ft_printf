/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:51:18 by mweir             #+#    #+#             */
/*   Updated: 2018/05/31 17:51:22 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(char *str, t_params *params)
{
	int i;

	i = 0;
	while (true)
	{
		if(str[i] == '-')
			params->justify = true;
		else if (str[i] == '+' || str[i] == '-')
			params->plus_neg = true;
		else if (str[i] == ' ')
			params->spaced = true;
		else if (str[i] == '#')
			params->hash = true;
		else if (str[i] == '0')
			params->pad = true;
		else
			break;
		i++;
	}
	return (i);
}

int	parse_width(char *str, t_params *params)
{
	int i;

	i = 0;
	while(true)
	{
		if (ft_atoi(&str[i]) > 0)
			params->wid_len = ft_atoi(&str[i]);
		else if (str[i] == '*')
			params->wid_len = -1;
		else
			break;
		i++;
	}
	return (i);
}

int	parse_precision(char *str, t_params *params)
{
	int i;
	int temp;
	i = 0;
	while(true)
	{
		if (str[i] == '.')
		{
			params->num_len = ft_atoi(&str[i + 1]);
			temp = params->num_len;
			while (temp != 0)
			{
				i++;
				temp /= 10;
			}
		}
		else if (str[i] == '*')
			params->p_wildcard = true;
		else
			break;
		i++;
	}

	return (i);
}

int	parse_length(char *str, t_params *params)
{
	int i;

	i = 0;
	while (true)
	{
		if (str[i] == 'h')
			params->modifer = (str[i] == 'h' && str[i + 1] == 'h') \
				 ? MODI_HH : MODI_H;
		else if (str[i] == 'l')
			params->modifer = (str[i] == 'l' && str[i + 1] == 'l') \
				? MODI_ll : MODI_l;
		else if (str[i] == 'j')
			params->modifer = MODI_J;
		else if (str[i] == 'z')
			params->modifer = MODI_Z;
		else if (str[i] == 't')
			params->modifer = MODI_t;
		else if (str[i] == 'L')
			params->modifer = MODI_Z;
		else
			break;
		i++;
	}
	return (i);
}

int parse_specifier(char *str, t_params *params)
{
	int i;
	i = 0;
	while (true)
	{
		if (str[i] == 'd' || str[i] == 'u' || str[i] == 'o' \
		|| str[i] == 'x' || str[i] == 'X' || str[i] == 'f' \
		|| str[i] == 'F' || str[i] == 'e' || str[i] == 'E' \
		|| str[i] == 'g' || str[i] == 'G' || str[i] == 'a' \
		|| str[i] == 'A' || str[i] == 'c' || str[i] == 's' \
		|| str[i] == 'p' || str[i] == 'n' || str[i] == '%')
				params->specifier = str[i];
		else
			break;
		i++;
	}
	//printf("%c", params->specifier);
	return (i);
}