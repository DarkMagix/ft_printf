/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:23:13 by mweir             #+#    #+#             */
/*   Updated: 2018/04/20 16:51:12 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_reverse_bits(unsigned char octet)
{
	unsigned char	r;
	unsigned		byte_len;

	r = 0;
	byte_len = 8;
	while (byte_len--)
	{
		r = (r << 1) | (octet & 1);
		octet >>= 1;
	}
	return (r);
}
