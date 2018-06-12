#include "libft.h"

void ft_wputstr(const wchar_t *str)
{
    int i;

    i = 0;
    while (str[i] != L'\0')
    {
        ft_wputchar(str[i]);
        i++;
    }
}