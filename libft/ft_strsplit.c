/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:07:26 by mweir             #+#    #+#             */
/*   Updated: 2018/04/22 17:40:32 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_w_l(char *str, int i)
{
	int size;

	size = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
		{
			size++;
			i++;
		}
	}
	return (size);
}

static int		ft_w_ct(char *str, char c)
{
	int len;
	int count;

	count = 0;
	len = 0;
	while (str[len])
	{
		if (str[len] == c)
		{
			count++;
		}
		len++;
	}
	return (count + 1);
}

char			**ft_strsplit(char *str, char c)
{
	char		**temp;
	int			i;
	int			j;
	int			k;

	j = 0;
	i = 0;
	if (!str || (temp = malloc(sizeof(char*) * (ft_w_ct(str, c) + 1))) == NULL)
		return (NULL);
	while (str[i])
	{
		while ((str[i] == c) && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((temp[j] = malloc(sizeof(char) * ft_w_l(str, i) + 1)) == NULL)
				return (NULL);
			while (str[i] != c && str[i])
				temp[j][k++] = str[i++];
			temp[j++][k] = '\0';
		}
	}
	temp[j] = NULL;
	return (temp);
}
