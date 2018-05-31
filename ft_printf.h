#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef int t_bool;
enum { false, true };

typedef enum e_enum
{
	MODI_HH = 1, 
	MODI_H,
	MODI_l,
	MODI_ll,
	MODI_J,
	MODI_Z,
	MODI_t,
	MODI_L
}            t_enum;

typedef struct      s_params
{
	//Flags
	t_bool justify;
	t_bool plus_neg;
	t_bool spaced;
	t_bool hash;
	t_bool pad;
	//Width
	int wid_len;
	//Precision
	int num_len;
	t_bool p_wildcard;
	//length
	char *buff;
	int modifer;
}                   t_params;

void init_params(t_params *params);
int print_str(va_list list);
int print_char(va_list list);
int print_integer(va_list list);
int print_hex(unsigned int n, int flag);
int read_data(t_params* params, const char *format);
void ft_parse(int flag, va_list arg);
int count_args(char *ptr);

int parse_flags(char *str, t_params *params);
#endif