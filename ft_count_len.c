#include "libftprintf.h"

static int	strlen_arg(char *str)
{
	if (!str)
		return (6);
	return (ft_strlen(str));
}

static int	ft_get_len_format(char c, va_list list)
{
	void	*tmp;

	if (c == 'd' || c == 'i')
		return (ft_nbrlen(va_arg(list, int)));
	else if (c == 'c' || c == '%')
	{
		if (c == 'c')
			(void)va_arg(list, int);
		return (1);
	}
	else if (c == 's')
		return (strlen_arg(va_arg(list, char *)));
	else if (c == 'u')
		return (ft_nbrlen_unsigned(va_arg(list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_nbrlen_hexa(va_arg(list, unsigned int)));
	else if (c == 'p')
	{
		tmp = va_arg(list, void *);
		if (tmp)
			return (14);
		return (5);
	}
	return (2);
}

int	ft_count_len(const char *frmt, va_list list)
{
	va_list		tmp_list;
	size_t		ret;

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
