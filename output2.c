#include "ft_printf.h"

int print_ptr(va_list list, t_params *params)
{
    int i;
 
    i = 0;
    uintmax_t num;
    char *str;

 
    //    printf("%d", thing);
    num = va_arg(list, uintmax_t);
    str = ft_uitoa_base(num, 16);
    params->buff = str;
    ft_putstr(params->buff);
    free(params->buff);
    return (i);
}

int print_wchar(va_list list, t_params *params)
{
    int i;

    i = 0;
    wchar_t let;
    
    let = va_arg(list, wchar_t);
    params = NULL;
    ft_wputchar(let);
    return (i);
}

int print_wstr(va_list list, t_params *params)
{
    int i;

    i = 0;
    wchar_t* str;
    
    str = va_arg(list, wchar_t*);
    params = NULL;
    ft_wputstr(str);
    return (i);
}

int print_octal(unsigned int n, int flag)
{
    	char hex[16];

	ft_strcpy(hex, "0123456789abcdef");
	if (n >= 8)
		return (print_hex(n / 8, flag) + print_hex(n % 8, flag));
	else
	{
		if (flag == 'o')
			ft_putchar(hex[n]);
		else
			ft_putchar(ft_toupper(hex[n]));
	}
	return (1);
}
