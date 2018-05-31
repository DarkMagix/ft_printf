#include "ft_printf.h"

// int parse_flags(char *str, t_params *params, va_list list)
// {
//     init_params(params);
//     char *s;
//     signed int num;
//     // char *test;
//     int i;

//     i = 0;
//     // test = ft_strchr()
//     if (str[i] == 's')
//     {
//         s = va_arg(list, char *);
//         ft_putstr(s);
//         i++;
//     }
//     else if (str[i] == 'd')
//     {
//         num = va_arg(list, signed int);
//         ft_putnbr(num);
//         i++;
//     }
//     return (i);
// }

int parse_flags(char *str, t_params *params)
{
    int i;

    i = 0;
    while (true)
    {
        if(str[i] == '-')
            params->justify = true;
        else if (str[i] == '+')
            params->plus_neg = true;
        else if (str[i] == ' ')
            params->spaced = true;
        else if (str[i] == '#')
            params->hash = true;
        else if (str[i] == '0')
            params->pad = true;
        else
            break;
        i++;
       
    }
     ft_putnbr(i);
        ft_putchar(' ');
    return (i);
}

// while (true)
// {
// 	if (char[i] == '#')
// 		set flag;
// 	else if(etc)
// 		set other flag;
// 	else
// 		break;
// 	i++;
// }
// void parse_width(char *str, t_params *params, va_list list)
// {
//     if (arr[i] && arr[i+1])
//         arr[i] 
//         arr[i+1]
//     //arr[i]
// }