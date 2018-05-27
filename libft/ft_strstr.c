/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:24:13 by mweir             #+#    #+#             */
/*   Updated: 2018/04/19 14:33:33 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char *start;
	char *end;

	if (!*to_find)
		return ((char*)str);
	while (*str != '\0')
	{
		start = str;
		end = to_find;
		while (*str != '\0' && *end != '\0' && *str == *end)
		{
			str++;
			end++;
		}
		if (!*end)
			return (start);
		str = start + 1;
	}
	return (0);
}
