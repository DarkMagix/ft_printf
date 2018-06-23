/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:33:27 by mweir             #+#    #+#             */
/*   Updated: 2018/06/20 17:33:28 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_wstrlen(const wchar_t *str)
{
	int	len;

	len = 0;
	while (str[len] != L'\0')
		len++;
	return (len);
}

void	ft_addpad(t_params *params)
{
	if (params->wid_len > 0 && !params->justify)
	{
		while (params->wid_len)
		{
			params->pad ? write(1, "0", 1) : write(1, " ", 1);
			params->wid_len -= 1;
		}
	}
	else if (params->wid_len > 0 && params->justify)
	{
		while (params->wid_len)
		{
			params->pad ? write(1, "0", 1) : write(1, " ", 1);
			params->wid_len -= 1;
		}
	}
}

void	display_wchars(t_params *params, wchar_t *w_s, int i)
{
	while (w_s[++i])
	{
		if (params->num_len && params->num_len < ft_wstrlen(w_s))
		{
			while (params->num_len--)
				ft_putchar(w_s[i]);
			break ;
		}
		ft_putchar(w_s[i]);
		params->inc++;
	}
}

void	ft_putwstr(va_list list, t_params *params)
{
	wchar_t	*w_s;
	int		i;

	i = -1;
	w_s = va_arg(list, wchar_t*);
	if (!w_s)
	{
		write(1, "(null)", 6);
		params->inc += 6;
		return ;
	}
	params->wid_len -= (ft_wstrlen(w_s) - params->num_len);
	params->justify ? params->pad = false : false;
	ft_addpad(params);
	display_wchars(params, w_s, i);
	ft_addpad(params);
}
