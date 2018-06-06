#include "ft_printf.h"

int u_length(uintmax_t nbr)
{
    int i;

    i = 0;
    while (nbr != 0)
    {
        nbr /= 10;
        i++;
    }
    return (i);
}