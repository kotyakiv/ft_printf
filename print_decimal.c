#include "ft_printf.h"

void	read_signedarg(long long *arg, t_flags *flag, va_list *ap)
{
	if (flag->modifier == 1)
		*arg = (char) va_arg(*ap, int);
	else if (flag->modifier == 2)
		*arg = (short) va_arg(*ap, int);
	else if (flag->modifier == 3)
		*arg = (long) va_arg(*ap, long long);
	else if (flag->modifier == 4)
		*arg = va_arg(*ap, long long);
	else
		*arg = (int) va_arg(*ap, int);
}

void	print_decimal(t_flags *flag, va_list *ap)
{
	long long	arg;
	int			num_dig;

	read_signedarg(&arg, flag, ap);
	num_dig = num_digit(arg, 10);
	check_minus(arg, flag);
	print_flag_space(flag);
	print_b_width(flag, num_dig);
	print_sign(flag, arg);
	print_precision(flag, num_dig);
	if (arg != 0)
		ft_putllunbr(ft_abs(arg));
	print_a_width(flag);
}


