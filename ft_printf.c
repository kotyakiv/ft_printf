#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list ap;
	t_flags	flag;
    int i;
    int total;
    int result;

    total = 0;
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
                total++;
				continue;
			}
            ++i;
            result = conversion_specification(str, &i, &flag, &ap);
            if (!result)
            {
                print_conversion(&flag, &ap);
                total += flag.total;
            }
            else if (result == 1)
                return (-1);
        }
        else
        {
			ft_putchar(str[i]);
            total++;
        }
        ++i;
    }
    va_end(ap);
    return (total);
}
