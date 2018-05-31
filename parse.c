#include "ft_printf.h"

int read_data(t_params* params, const char *format)
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
			//i += parse_width
			//parse precision
			//parse length
			//format string()
			//print
		}
		i++;
	}
	//to shut up the compiler
	return (0);
}

