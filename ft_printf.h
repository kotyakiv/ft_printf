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
	int		star;
	int 	width;
	int 	precision;
	int		modifier;
	int		print_nothing;
	char	specifier;
}				t_flags;


void	ft_printf(const char *str, ...);

void	conversion_specification(const char *str, int *i, t_flags *flag);
void	print_conversion(t_flags *flag, va_list *ap);
int		num_digit(long long  num, int base);
char	*dem_to_base(long long num, int base);

void	print_decimal(t_flags *flag, va_list *ap);
void	print_octal(t_flags *flag, va_list *ap);
void	print_hexadecimal(t_flags *flag, va_list *ap);
void	print_unsigned(t_flags *flag, va_list *ap);
void	print_float(t_flags *flag, va_list *ap);

/*
**	print_flags
*/

void	print_sign(t_flags *flag, long long arg);
void	print_flag_space(t_flags *flag);
void	print_b_width(t_flags *flag, int num_dig);
void	print_precision(t_flags *flag, int num_dig);
void	check_minus(long long arg, t_flags *flag);
void	print_a_width(t_flags *flag);
/*
**	sub-functions
*/
void		ft_putllnbr(long long n);
void		ft_putllunbr(unsigned long long n);
long long 	ft_bigger(long long a, long long b);
long long 	ft_smaller(long long a, long long b);
long long 	ft_abs(long long a);
void		str_toupper(char *str);


#endif