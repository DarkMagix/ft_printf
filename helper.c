#include "ft_printf.h"

int count_args(char *ptr)
{
    int i;
    int flags;
    
    flags = 0;
    i = 0;
    while (ptr[i] != '\0')
    {
        if (ptr[i] == '%' || (ptr[i] == '%' && ptr[i + 1] == '%'))
        {
            printf("%c%c\n", ptr[i],ptr[i + 1]);
            i++;
            flags++;
        }
        i++;
    }
    return (flags);
}

long long sint_flags(va_list list, t_params *params)
{
    if(params->specifier == MODI_ll)
        return (va_arg(list, long long));
    else if (params->specifier == MODI_l)
        return ((long long)va_arg(list, long int));
    else if (params->specifier == MODI_HH)
        return ((char)va_arg(list, int));
    else if (params->specifier == MODI_H)
        return ((short)va_arg(list, int));
    else if (params->specifier == MODI_J)
        return (va_arg(list, long long));
    else if (params->specifier == MODI_Z)
        return ((long long)va_arg(list, size_t));
    return ((long long)va_arg(list, int));
}

unsigned long long	uint_flags(va_list list, t_params *params)
{
	if (params->specifier == MODI_ll)
		return (va_arg(list, unsigned long long));
	else if (params->specifier == MODI_l)
		return ((unsigned long long)va_arg(list, unsigned long));
	else if (params->specifier == MODI_HH)
		return ((unsigned char)va_arg(list, unsigned int));
	else if (params->specifier == MODI_H)
		return ((unsigned short int)va_arg(list, unsigned int));
	else if (params->specifier == MODI_J)
		return ((unsigned long long)va_arg(list, unsigned long long));
	else if (params->specifier== MODI_Z)
		return ((unsigned long long)va_arg(list, size_t));
	return (va_arg(list, unsigned int));
}