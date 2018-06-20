#include "ft_printf.h"

int ft_wstrlen(const wchar_t* str)
{
    int	len;

	len = 0;
	while (str[len] != L'\0')
		len++;
	return (len);
}
void ft_putwstr(va_list list, t_params *params)
{
    wchar_t *w_s;
    int i;

    i = -1;
    w_s = va_arg(list, wchar_t*);
    params->wid_len -= (ft_wstrlen(w_s) - params->num_len);
    params->justify ? params->pad = false : false;
    if (params->wid_len > 0 && !params->justify)
    {
        while(params->wid_len)
        {
            params->pad ? write(1, "0", 1) : write(1, " ", 1);
            params->wid_len -=1;
        }
    }
    while(w_s[++i])
    {
        if(params->num_len && params->num_len < ft_wstrlen(w_s))
        {
            while(params->num_len--)
                ft_putchar(w_s[i]);
            break;
        }
        ft_putchar(w_s[i]);
        params->inc++;
    }
    if (params->wid_len > 0 && params->justify)
        while(params->wid_len)
        {
            params->pad ? write(1, "0", 1) : write(1, " ", 1);
            params->wid_len-=1;
        }
}