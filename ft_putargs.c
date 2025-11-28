#include "libftprintf.h"

int	ft_putargs(va_list list, t_flags flags, char c, int *ret)
{
	// return 1;
	if (c == 'd' || c == 'i' || c == 'c')
		ft_put_integer();
	else if (c == 'x' || c == 'X' || c == 'u')
		ft_put_unsigned();
	else if (c == 'p')
		ft_put_address();
	else if (c == 's')
		ft_putstr();
	else if (c == '%')
		ft_putchar('%');
	 return (0);

}
