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
	int 	apostrophe;
	int 	length;
	int 	width;
	int		modifier;
	char	specifier;
}				t_flags;

void	ft_printf(const char *str, ...);
void	conversion_specification(const char *str, int *i, t_flags *flag);
void	print_conversion(t_flags flag, va_list *ap);
char	*dem_to_base(long long num, int base);




#endif