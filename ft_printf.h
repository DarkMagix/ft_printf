#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/includes/libft.h"

int print_str(va_list list);
int print_char(va_list list);
int print_integer(va_list list);
int print_hex(unsigned int n, int flag);
#endif
