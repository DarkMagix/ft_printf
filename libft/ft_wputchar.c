#include "libft.h"

void ft_wputchar(wchar_t c)
{
    write(1, &c, 1);
}