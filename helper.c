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

intmax_t sint_flags(va_list list, t_params *params)
{
    intmax_t nbr;
   
    nbr = va_arg(list, int);
    if(params->modifer == MODI_HH)
    {
        printf("HH\n");
        nbr = (char)nbr;
    }
    else if (params->modifer == MODI_H)
    {
        printf("H\n");
        nbr = (short int)nbr;
    }
    else if (params->modifer == MODI_l)
    {
        printf("L\n");
        nbr = (long int)nbr;
    }
    else if (params->modifer == MODI_ll)
    {
        printf("LL\n");
        nbr = (long long int)nbr;
    }
    else if (params->modifer == MODI_J)
    {
        printf("J\n");
        nbr =  (intmax_t)nbr;
    }
    else if (params->modifer == MODI_Z)
    {
        printf("Z\n");
        nbr = (size_t)nbr;
    }
    return (nbr);
}

uintmax_t	uint_flags(va_list list, t_params *params)
{
    uintmax_t nbr;

    nbr = va_arg(list, uintmax_t);
    if(params->modifer == MODI_HH)
        nbr = (unsigned char)nbr;
    else if (params->modifer == MODI_H)
        nbr = (unsigned short int)nbr;
    else if (params->modifer == MODI_l)
        nbr = (unsigned long int)nbr;
    else if (params->modifer == MODI_ll)
        nbr = (unsigned long long int)nbr;
    else if (params->modifer == MODI_J)
        nbr =  (uintmax_t)nbr;
    else if (params->modifer == MODI_Z)
        nbr = (size_t)nbr;
    else
        nbr = (unsigned int)nbr;
    return (nbr);
}