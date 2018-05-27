/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:21:37 by mweir             #+#    #+#             */
/*   Updated: 2018/04/19 14:03:23 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	if (c == '\0')
		return ((char*)tmp);
	while (--tmp >= s)
		if (c == *tmp)
			return ((char*)tmp);
	return (NULL);
}
