#include "libftprintf.h"

static char	*get_string(char *dest, const char *frmt, va_list list, int *len)
{
	char	*p_start;

	if (!frmt)
		return (dest);
	while (*frmt)
	{
		p_start = (char *)frmt;
		while (*frmt && *frmt != '%')
			frmt++;
		dest = ft_strncat(dest, p_start, frmt - p_start);
		if (*(frmt) == '%')
		{
			dest = ft_strcat_format(dest, *(frmt + 1), list, len);
			frmt += 2;
		}
	};
	*len += ft_strlen(dest);
	return (dest);
}

int	ft_printf(const char *frmt, ...)
{
	va_list	list;
	char	*tmp;
	int		len;

	va_start(list, frmt);
	len = ft_count_len(frmt, list);
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (-1);
	len = 0;
	get_string(tmp, frmt, list, &len);
	ft_putstr(tmp);
	free(tmp);
	va_end(list);
	return (len);
}
