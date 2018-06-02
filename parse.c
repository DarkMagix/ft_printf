#include "ft_printf.h"

int read_data(t_params* params, const char *format, va_list args)
{
	char *ptr;
	int i;
	i = 0;
	ptr = (char *)format;
	while (ptr[i] != '\0')
	{
		init_params(params);
		if (ptr[i] == '%' && ptr[i + 1])     
		{
			i += parse_flags(&ptr[i + 1], params);
			i += parse_width(&ptr[i + 1], params);
			i += parse_precision(&ptr[i + 1], params);
			i += parse_length(&ptr[i + 1], params);
			i += parse_specifier(&ptr[i + 1], params);
			ft_parse(params->specifier, args, params);
			//print
		}
		
		i++;
	}
	//to shut up the compiler
	return (0);
}

