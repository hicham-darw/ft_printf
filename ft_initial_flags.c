#include "liftprintf.h"


char	*ft_initial_flags(char *s, t_list *flags)
{
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
		s++;
	}
	if (!*s)
		return (NULL);
	return (s);
}
