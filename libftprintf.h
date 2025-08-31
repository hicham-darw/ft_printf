#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>

int		ft_count_len(const char *s, va_list list);
char	*ft_strcat_format(char *dest, char c, va_list list, int *len);
char	*ft_strcat_one_char(char *dest, char c);
int		ft_printf(const char *format, ...);
char	*get_hexa(long n);

#endif
