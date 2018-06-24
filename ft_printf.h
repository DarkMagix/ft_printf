/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mweir <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:46:09 by mweir             #+#    #+#             */
/*   Updated: 2018/06/21 15:46:10 by mweir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdint.h>
# define IS_NEG(x) (x < 0) ? (1) : (0)

typedef int	t_bool;
enum { false, true };

typedef enum	e_enum
{
	MODI_HH = 1,
	MODI_H,
	MODI_l,
	MODI_ll,
	MODI_J,
	MODI_Z,
	MODI_t,
	MODI_L
}				t_enum;

typedef struct	s_params
{
	t_bool					justify;
	t_bool					plus_neg;
	t_bool					spaced;
	t_bool					hash;
	t_bool					pad;
	int						wid_len;
	int						num_len;
	t_bool					has_num_len;
	t_bool					p_wildcard;
	char					*buff;
	int						modifer;
	int						specifier;
	t_bool					is_neg;
	unsigned long long int	u;
	long long int			i;
	int						zeroes;
	int						spaces;
	int						len;
	char					sign;
	int						inc;
	wchar_t					*w_s;
}				t_params;

void			display_wchars(t_params *params, wchar_t *w_s, int i);
void			init_params(t_params *params);
int				read_data(t_params *params, char *format, va_list list);
int				ft_printf(const char *frmt, ...);
void			ft_parse(int flag, va_list arg, t_params *params);
void			ft_putstring(va_list list, t_params *params);
void			ft_addpad(t_params *params);
void			ft_putwstr(va_list list, t_params *params);
int				count_args(char *ptr);
int				parse_flags(char *str, t_params *params);
int				parse_width(char *str, t_params *params, va_list list);
int				parse_precision(char *str, t_params *params, va_list list);
int				parse_length(char *str, t_params *params);
int				parse_specifier(const char *format,
					va_list args, t_params *params);
void			sint_flags(va_list list, t_params *params);
void			uint_flags(va_list list, t_params *params);
int				print_char(va_list list, t_params *params);
int				print_integer(va_list list, t_params *params);
int				print_str(va_list list, t_params *params);
int				print_hex(va_list list, t_params *params);
int				print_sint(va_list list, t_params *params, int flag);
int				print_uint(va_list list, t_params *params, int flag);
void			print_words(t_params *params, char *s, int i);
int				print_wchar(va_list list, t_params *params);
int				print_length(t_params *params);
int				print_wstr(va_list list, t_params *params);
int				print_octal(va_list list, t_params *params, int flag);
void			print_spaces(t_params *params);
void			print_chars(t_params *params, char c, int n);
int				print_float(va_list list);
void			print_nums(t_params *params);
void			to_upper(t_params *params);
void			prepare_hex(t_params *params);
void			prepare_octal(t_params *params);
void			setup_hex(va_list list, t_params *params);
void			setup_unint(va_list list, t_params *params);
void			setup_int(va_list list, t_params *params);
void			setup_octal(va_list list, t_params *params);
void			setup_ptr(va_list list, t_params *params);
void			check_sign(t_params *params);
void			ft_print_pers(t_params *params);
void			handle_extra_hex(t_params *params);
int				valid_arg(int c);
void			count_index(int temp, int *i);
void			uint_njustify(t_params *params);
void			uint_justify(t_params *params);
void			justify_chars(t_params *params, char c);
void			pre_check(t_params *params);
void			n_justify_hash(t_params *params);
#endif
