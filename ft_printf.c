#include "libftprintf.h"

int	ft_printf(const char *frmt, ...)
{
	va_list	list;
	char	*tmp;
	int	len;
	char	*p_start;
	
	va_start(list, frmt);
	len = ft_count_len(frmt, list);
	tmp = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (-1);
	while (*frmt)
	{
		p_start = (char *)frmt;
		while(*frmt && *frmt != '%')
			frmt++;
		tmp = ft_strncat(tmp, (frmt  - (frmt - p_start)), frmt - p_start);
		if (*(frmt) == '%')
		{
			tmp = ft_strcat_format(tmp, *(frmt + 1),list);
			frmt += 2;
		}
	}
	ft_putstr(tmp);
	va_end(list);
	return (len);
}
