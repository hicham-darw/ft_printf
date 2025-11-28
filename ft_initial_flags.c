#include "libftprintf.h"

static char	*get_number(char *s, int *width)
{
	*width = 0;
	while (*s && *s >= 48 && *s <= 57)
	{
		*width = (*width * 10) + (*s - 48);
		s += 1;
	}
	return (s);
}

static t_flags	*ft_zeros(t_flags *flags)
{
	flags->hashtag = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->call_back = NULL;
	return (flags);
}

char	*ft_initial_flags(char *s, t_flags *flags)
{
	ft_zeros(flags);
	while (*s && !ft_isformat(*s))
	{
		if (*s == '+')
			flags->plus = 1;
		else if (*s == '-')
			flags->minus = 1;
		else if (*s == '#')
			flags->hashtag = 1;
		else if (*s == ' ')
			flags->space = 1;
		else if (*s == '0')
			flags->zero = 1;
		else if (*s >= 48 && *s <= 57)
			s = get_number(s, &flags->width) - 1;
		else if (*s == '.')
			s = get_number(++s, &flags->precision) - 1;
		s++;
	}
	return (s);
}
