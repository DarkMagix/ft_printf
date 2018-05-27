/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:29:55 by mweir             #+#    #+#             */
/*   Updated: 2018/04/18 13:58:44 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *data, int value, size_t len)
{
	char	*ptr;
	size_t	index;

	ptr = data;
	index = 0;
	if (len == 0)
		return (data);
	while (index < len)
		ptr[index++] = value;
	return (ptr);
}
