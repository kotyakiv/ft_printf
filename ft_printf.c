#include "ft_printf.h"

void ft_printf(const char *str, ...)
{
    va_list ap;
	t_flags	flag;
    int i;
	
    i = 0;
    va_start(ap, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
			if (str[i + 1] == '%')
			{
				ft_putchar('%');
                i += 2;
				continue;
			}
            ++i;
			conversion_specification(str, &i, &flag);
			print_conversion(&flag, &ap);
        }
        else
			ft_putchar(str[i]);
        ++i;
    }
    va_end(ap);
}
