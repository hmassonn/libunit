/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lu_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:49:31 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/10 18:49:53 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LU_PRINTF_H
# define LU_PRINTF_H

# define BUFER_SIZ 2048
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <wchar.h>
# include <inttypes.h>
# include "lu_libft.h"

typedef struct	s_struct
{
	va_list			arg;
	va_list			arg_cp;
	char			*format_cp;
	int				len;
	char			buffer[BUFER_SIZ];
	int				i;
	int				fd;
	int				(*func_ptr[25])(struct s_struct *);
	char			dollar;
	char			hashtag;
	char			zero;
	char			minus;
	char			plus;
	char			space;
	char			quote;
	int				width;
	int				precision;
	int				pre_on;
	char			h;
	char			hh;
	char			l;
	char			ll;
	char			j;
	char			z;
	char			upl;
	char			conv_letter;
	int				arg_conv;
}				t_struct;

int				lu_printf(const char *format, ...);
size_t			lu_wstrlen(wchar_t *str);
int				adjust_size(int i, wchar_t *str);
int				lu_wcharlen(int c);
void			init_struct(t_struct *core);
void			init_modifier(t_struct *core);
void			init_var(t_struct *core);
void			print_buffer(t_struct *core);
void			fill_buf_left(t_struct *core, int slen, char *str, char *htag);
void			fill_buf_right(t_struct *core, int slen, char *str, char *htag);
void			fill_buf_nchar(t_struct *core, int start, int end, char c);
void			fill_buf(t_struct *core, int start, int end, char c);
void			put_c_buf(t_struct *core, unsigned char c);
void			put_s_buf(t_struct *core, char *str);
int				manage_arg(t_struct *core, char **format);
int				get_conv(t_struct *core, char **format);
void			get_options(t_struct *core, char **format);
int				get_width(t_struct *core, char **format);
void			get_precision(t_struct *core, char **format);
void			get_modifier(t_struct *core, char **format);
uintmax_t		set_modifier(t_struct *core);
void			set_modifier_double(t_struct *core, long double *d);
int				conv_percent(t_struct *core);
int				conv_i(t_struct *core);
int				conv_p(t_struct *core);
int				conv_b(t_struct *core);
int				conv_n(t_struct *core);
int				conv_low_d(t_struct *core);
int				conv_low_u(t_struct *core);
int				conv_low_o(t_struct *core);
int				conv_low_x(t_struct *core);
int				conv_low_c(t_struct *core);
int				conv_low_s(t_struct *core);
int				conv_low_f(t_struct *core);
int				conv_low_e(t_struct *core);
int				conv_low_a(t_struct *core);
int				conv_low_g(t_struct *core);
int				conv_up_u(t_struct *core);
int				conv_up_o(t_struct *core);
int				conv_up_x(t_struct *core);
int				conv_up_c(t_struct *core);
int				conv_up_s(t_struct *core);
int				conv_up_d(t_struct *core);
int				conv_up_f(t_struct *core);
int				conv_up_e(t_struct *core);
int				conv_up_g(t_struct *core);
int				conv_up_a(t_struct *core);
int				which_conv_letter(t_struct *core);
void			put_unicode(t_struct *core, int c);
void			get_arg_conv(t_struct *core, char **format);
void			set_colors(t_struct *core, char **format);
int				set_column(t_struct *core, char **format);
char			*spacing_number(t_struct *core, int signed_nb, int base);
int				manage_arg_dollar(t_struct *core, char **format);
void			get_n_arg(t_struct *core, int nb_arg);
int				nblen(intmax_t nb);
void			itoa_double(char *str, intmax_t entier, int base, int nb_zero);
void			update_exp(char *str, char *start, int *exp);
void			nine_case(char *str);
void			nine_case_a(char *str, int *exp);
void			nine_case_e(char *str, int *exp, char *start);
void			round_nb(char *str);
void			round_number_a(char *str, int *exp);
void			round_number_e(t_struct *core, char *str, int *exp,
				char *start);
int				get_exp_a(long double *d);
int				get_exp_a_long(long double *d);
void			remove_zero_e(t_struct *core, char *str);
void			set_exp_zero(t_struct *core, char *str);
void			set_exp(t_struct *core, char *str, int exp);
void			set_dot_sign_exp2(t_struct *core, char *str, int *i);
void			update_plus_and_space(t_struct *core, long double d);
void			fill_buf_lelu_double(t_struct *core, int slen, char *str);
void			fill_buf_right_double(t_struct *core, int slen, char *str);

#endif
