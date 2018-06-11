#include "libft.h"

size_t ft_wcharlen(wchar_t c)
{
    if (c <= 0x007F)
		return (1);
	else if (c <= 0x07FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
    return (4);
}
