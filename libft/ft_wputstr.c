#include "libft.h"

void ft_wputstr(const wchar_t *str)
{
    int size;

    size = ft_wstrlen(str);
    if (!str)
        return ;
    write(1, &str[0], size);
}