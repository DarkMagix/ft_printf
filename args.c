/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:51:18 by mweir             #+#    #+#             */
/*   Updated: 2018/06/02 17:17:57 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(char *str, t_params *params)
{
	int i;

	i = 0;
	while (true)
	{
		if (str[i] == '-')
			params->justify = true;
		else if (str[i] == '+')
			params->plus_neg = true;
		else if (str[i] == ' ')
			params->spaced = true;
		else if (str[i] == '#')
			params->hash = true;
		else if (str[i] == '0')
			params->pad = true;
		else
		  {
		    printf("Nothing Found\n");
			break ;
		  }
		i++;
	}
	return (i);
}

int	parse_width(char *str, t_params *params)
{
	int i;
	int	skip;

	i = 0;
	skip = 0;
	if (ft_atoi(&str[i]) > 0)
	{
		params->wid_len = ft_atoi(&str[i]);
		skip = params->wid_len;
		while (skip != 0)
		{
			i++;
			skip /= 10;
		}
	}
	while (true)
	{
		if (str[i] == '*')
			params->wid_len = -1;
		else
			break ;
		i++;
	}
	return (i);
}

int	parse_precision(char *str, t_params *params)
{
	int i;
	int temp;

	i = 0;
	while (true)
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
			break ;
		i++;
	}
	return (i);
}

int	parse_length(char *str, t_params *params)
{
	int i;

	i = 0;
	printf("im in parse_length");
	while (true)
	{
		if (str[i] == 'h')
		  {
			params->modifer = (str[i] == 'h' && str[i + 1] == 'h') \
				? MODI_HH : MODI_H;
	 
		  }
		else if (str[i] == 'l')
		  {
			params->modifer = (str[i] == 'l' && str[i + 1] == 'l') \
				? MODI_ll : MODI_l;
		  }
		else if (str[i] == 'j')
			params->modifer = MODI_J;
		else if (str[i] == 'z')
			params->modifer = MODI_Z;
		else if (str[i] == 't')
			params->modifer = MODI_t;
		else if (str[i] == 'L')
			params->modifer = MODI_Z;
		else
			break ;
		i++;
	}
	printf("Modifier: %d\n", params->modifer);	
	return (i);
}

int	parse_specifier(const char *format, va_list args, t_params *params)
{
	int i;

	i = 0;
	init_params(params);
	while (*format)
	{
		if (*format == '%')
		{
			if (valid_arg(*(format + 1)))
				format += read_data(params, (char *)(format + 1)) + 1;
			params->specifier = *format;
			ft_parse(params->specifier, args, params);
		}
		else
			ft_putchar(*format);
		init_params(params);
		format++;
	}
	return (i);
}
