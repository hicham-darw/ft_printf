#include "libftprintf.h"

static int	ft_get_len_format(char c, va_list list)
{
	if (c == 'd' || c  == 'i')
		return (ft_nbrlen(va_arg(list, int)));
	else if (c  == 'c' || c == '%')
	{
		if (c == 'c')
			(void)va_arg(list, int);
		return (1);
	}else if (c == 's')
		return (ft_strlen(va_arg(list, char *)));
	else if (c == 'u')
		return (ft_nbrlen_unsigned(va_arg(list, unsigned int)));
	else if (c == 'x' || c == 'X'){
		return (ft_nbrlen_hexa(va_arg(list, unsigned int)));
	}else if (c == 'p')
	{
		(void)va_arg(list, void*);
		return (14);
	}
	return (2);
}

int	ft_count_len(const char *frmt, va_list list)
{
	va_list tmp_list;
	size_t	ret;

	va_copy(tmp_list, list);
	ret = 0;
	while (*frmt)
	{
		if (*frmt != '%')
			ret++;
		else
			ret += ft_get_len_format(*(++frmt), tmp_list);
		frmt++;
	}
	va_end(tmp_list);
	return (ret);
}
