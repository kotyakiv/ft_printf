#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_flags
{
	int		hash;
	int 	zero;
	int 	minus;
	int 	plus;
	int 	space;
	int 	width;
	int 	precision;
	int		modifier;
	char	specifier;
	int		negative;
	int		print_nothing;
	int		arg_zero;
	int		zero_printed;
	int		spec_num;
	int		total;
}				t_flags;

/*
**	ft_printf
*/

int	ft_printf(const char *str, ...);

/*
**	conversion_specification
*/

void	flag_init(t_flags *flag);
void	read_flags(const char *str, int *i, t_flags *flag);
void	read_precision_width(const char *str, int *i, t_flags *flag, int is_prec);
void	read_modifier(const char *str, int *i, t_flags *flag);
int		read_specifier(const char *str, int *i, t_flags *flag);
void	flags_override(t_flags *flag);
int	conversion_specification(const char *str, int *i, t_flags *flag, va_list *ap);
void	read_star(int *i, t_flags *flag, va_list *ap, int is_prec);

/*
**	to_base
*/

void	ft_strrev(char *str);
int		num_undigit(unsigned long long  num, int base);
int		num_digit(long long  num, int base);
char	ft_digit(unsigned long long  num, int base);
char	*dem_to_base(unsigned long long num, int base);

/*
**	print_flags
*/

void	check_unarg(unsigned long long arg, t_flags *flag);
void	check_minus_arg(long long arg, t_flags *flag);
void	check_minus_f(long double arg, t_flags *flag);
void	print_sign(t_flags *flag);
void	print_flag_space(t_flags *flag);
void	print_precision(t_flags *flag, int num_dig);
void	print_width(t_flags *flag, int num_dig, int first_call);
void	print_hash(t_flags *flag);
void	width_first_call(t_flags *flag, int num_dig);
void	print_sign_or_hash(t_flags *flag, int num_dig);
void	check_hash_width(t_flags *flag);
/*
**	sub-functions
*/

void		ft_putllnbr(long long n);
void		ft_putllunbr(unsigned long long n);
long long 	ft_bigger(long long a, long long b);
long long 	ft_smaller(long long a, long long b);
void		str_toupper(char *str);

/*
**	print_decimal
*/

void	read_signedarg(long long *arg, t_flags *flag, va_list *ap);
void	print_decimal(t_flags *flag, va_list *ap);

/*
**	print_unsigned
*/

void	read_unsignedarg(unsigned long long *arg, t_flags *flag, va_list *ap);
void	print_unsigned(t_flags *flag, va_list *ap);
void	print_octal(t_flags *flag, va_list *ap);
void	print_hexadecimal(t_flags *flag, va_list *ap);

/*
**	print_conversion
*/

void	print_char(t_flags *flag, va_list *ap);
void	print_pointer(t_flags *flag, va_list *ap);
void	print_str(t_flags *flag, va_list *ap);
void	print_conversion(t_flags *flag, va_list *ap);

/*
**	print_float
*/

void	print_float(t_flags *flag, va_list *ap);

#endif