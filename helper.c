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
