#include "libft.h"

size_t ft_wstrlen(const wchar_t *str)
{
    size_t i;
    size_t sum;

    i = 0;
    sum = 0;
    while(str[i] != L'\0')
      {
	sum += ft_wcharlen(str[i]);
        i++;
      }
    return (i);
}
