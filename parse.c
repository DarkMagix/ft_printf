#include "ft_printf.h"

int read_data(t_params* params,char *format)
{
	printf("Entered Read Data\n");
	int i;
	i = 0;
	i += parse_flags(&format[i], params);
	i += parse_width(&format[i], params);
	i += parse_precision(&format[i], params);
	i += parse_length(&format[i], params);
	return (i);
}

