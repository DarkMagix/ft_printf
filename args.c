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

// int parse_flags(char *str, t_params *params, va_list list)
// {
//     init_params(params);
//     char *s;
//     signed int num;
//     // char *test;
//     int i;

//     i = 0;
//     // test = ft_strchr()
//     if (str[i] == 's')
//     {
//         s = va_arg(list, char *);
//         ft_putstr(s);
//         i++;
//     }
//     else if (str[i] == 'd')
//     {
//         num = va_arg(list, signed int);
//         ft_putnbr(num);
//         i++;
//     }
//     return (i);
// }

int	parse_flags(char *str, t_params *params)
{
	//printf("Entering Parse Flags\n");
	int i;
//printf("%s\n", str);
	i = 0;
	while (true)
	{
		if(str[i] == '-')
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
			break;
		i++;

	}
	// ft_putnbr(i);
		//ft_putchar(' ');
	return (i);
}

int	parse_width(char *str, t_params *params)
{
	//printf("Entering Parse Width\n");
	int i;
//printf("%s\n", str);
	i = 0;
	while(true)
	{
		if (ft_atoi(&str[i]) > 0)
		{
			params->wid_len = ft_atoi(&str[i]);
		  //  ft_putstr("Width of: ");
			//ft_putnbr(params->wid_len);
		}
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
	//printf("Entering Parse Precision\n");
	int i;
//printf("%s\n", str);
	i = 0;
	while(true)
	{
		if (str[i] == '.')
		{
			params->num_len = ft_atoi(&str[i + 1]);
			i++;
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
	//printf("Entering Parse Length\n");
	int i;

	i = 0;
	//printf("%s\n", str);
	while (true)
	{
		//printf("%c\n", str[i]);
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
		{
			params->modifer = MODI_J;
			printf("found j\n");
		}
		else if (str[i] == 'z')
		{
			params->modifer = MODI_Z;
			printf("found z\n");
		}
		else if (str[i] == 't')
		{
			params->modifer = MODI_t;
			printf("found t\n");
		}
		else if (str[i] == 'L')
		{
			params->modifer = MODI_Z;
			printf("Found L\n");
		}
		else
			break;
		i++;
	}
	if (params->modifer == MODI_l ||params->modifer ==  MODI_ll)
		printf("\nFound l or ll\n");
	if (params->modifer == MODI_H ||params->modifer ==  MODI_HH)
		printf("\nFound h or hh\n");
	return (i);
}

int parse_specifier(char *str, t_params *params)
{
	//printf("Entering Parse Specifier\n");
	
	//  if(spot = ft_strchr("cdfs", test[i]))
		// {
		// 	printf("Found ");
		// 	printf("%c\n", test[i]);
		// }
		// else
		// {
		// 	printf("Not Found ");
		// 	printf("%c\n", test[i]);
		// }
	int i;
	i = 0;
	//printf("%c\n", str[i]);
	while (true)
	{
		//"duoxXfFeEgGaAcspn%"
		if (str[i] == 'd' || str[i] == 'u' || str[i] == 'o' \
		|| str[i] == 'x' || str[i] == 'X' || str[i] == 'f' \
		|| str[i] == 'F' || str[i] == 'e' || str[i] == 'E' \
		|| str[i] == 'g' || str[i] == 'G' || str[i] == 'a' \
		|| str[i] == 'A' || str[i] == 'c' || str[i] == 's' \
		|| str[i] == 'p' || str[i] == 'n' || str[i] == '%')
			{
				params->specifier = str[i];
				printf(" | found a %c | ", str[i]);
			}
		else
			break;
		i++;
	}
	return (i);
}

// int parse_length(char *str)
// {

// }
// while (true)
// {
// 	if (char[i] == '#')
// 		set flag;
// 	else if(etc)
// 		set other flag;
// 	else
// 		break;
// 	i++;
// }
// void parse_width(char *str, t_params *params, va_list list)
// {
//     if (arr[i] && arr[i+1])
//         arr[i]
//         arr[i+1]
//     //arr[i]
// }
