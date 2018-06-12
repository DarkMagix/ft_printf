#include "libft.h"

void ft_wputchar(wchar_t c)
{
    write(1, &c, 1);
    /*
    if (c <= 127)
        ft_putchar(c);
    else if (c <= 2047)
    {
        ft_putchar((c >> 6) + 0xC0);
        ft_putchar((c & 0x3F) + 0x80);
    }
    else if (c <= 65535)
    {
        ft_putchar((c >> 12) + 0xE0);
        ft_putchar(((c >> 6) & 0x3F) + 0x80);
        ft_putchar((c & 0x3F) + 0x80);
    }
    else if (c <= 1114111)
    {
        ft_putchar((c >> 18) + 0xF0);
        ft_putchar(((c >> 12) & 0x3F) + 0x80);
        ft_putchar(((c >> 6) & 0x3F) + 0x80);git
        ft_putchar((c & 0x3F) + 0x80);
    }
    */
}