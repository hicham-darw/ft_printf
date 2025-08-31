#include "libftprintf.h"

static char	*uplow_hex(char *tmp, char c)
{
	if (c == 'X')
		return (ft_strupcase(tmp));
	return (tmp);
}

static char	*cat_i_arg(char *dest, char *src)
{
	if (!src)
		return (dest);
	ft_strcat(dest, src);
	free(src);
	return (dest);
}

static char	*get_adress(char *dest, char *src)
{
	long	address;
	char	*ptr;
	char	*tmp;

	if (src)
		ptr = ft_memalloc(sizeof(char) * 15);
	else
		ptr = ft_memalloc(sizeof(char) * 6);
	if (!ptr)
		return (NULL);
	if (src)
	{
		ft_strcpy(ptr, "0x");
		address = (long)src;
		tmp = get_hexa(address);
		ft_strlcat(ptr, tmp, 15);
		free(tmp);
	}
	else
		ft_strcpy(ptr, "(nil)");
	ft_strcat(dest, ptr);
	free(ptr);
	return (dest);
}

static char	*invalid_format(char *dest, char c)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(3);
	if (!tmp)
		return (NULL);
	tmp[0] = '%';
	tmp[1] = c;
	ft_strcat(dest, tmp);
	free(tmp);
	return (dest);
}

static char	*char_format(char *dest, int c, int *len)
{
	if (c == 0)
		*len += 1;
	ft_strcat_one_char(dest, c);
	return (dest);
}

char	*ft_strcat_format(char *d, char c, va_list list, int *len)
{
	char	*tmp;

	if (c == 'd' || c == 'i')
		return (cat_i_arg(d, ft_ltoa((long)va_arg(list, int))));
	else if (c == 's')
	{
		tmp = va_arg(list, char *);
		if (!tmp)
			return (ft_strcat(d, "(null)"));
		return (ft_strcat(d, tmp));
	}
	else if (c == 'c')
		return (char_format(d, va_arg(list, int), len));
	else if (c == 37)
		return (ft_strcat_one_char(d, c));
	else if (c == 'u')
		return (cat_i_arg(d, ft_ltoa((long)va_arg(list, unsigned int))));
	else if (c == 'x' || c == 'X')
		return (cat_i_arg(d, uplow_hex(get_hexa((va_arg(list, int))), c)));
	else if (c == 'p')
		return (get_adress(d, va_arg(list, void *)));
	else
		return (invalid_format(d, c));
}
