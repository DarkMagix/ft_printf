#include "ft_printf.h"

void format_ptr(char *str, t_params *params)
{
    char *temp;
    size_t size_str;
    char *hex = "0x";
 
    size_str = ft_strlen(str);
    temp = ft_strjoin(hex, str);
    params->buff = temp;
}
