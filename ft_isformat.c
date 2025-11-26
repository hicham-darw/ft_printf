#include "libftprintf.h"

int	ft_isflags(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || '%')
		return (1);
	return (0);
}
