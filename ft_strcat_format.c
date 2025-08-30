#include "libftprintf.h"

static char	*strcat_one_char(char *dest,char c)
{
	int	len;

	if (!dest)
		return (0);
	len = 0;
	while (dest[len])
		len++;
	dest[len++] = c;
	dest[len] = '\0';
	return (dest);
}

static char	*by_uplow_hex(char *tmp, char c)
{
	if (c == 'X')
		return (ft_strupcase(tmp));
	return (tmp);
}

static char	*is_int_format(char *dest, char *src)
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

	ptr = ft_memalloc(sizeof(char) * 15);
	if (!ptr)
		return (NULL);
	ft_strcpy(ptr, "0x");
	address = (long)src;
	tmp = get_hexa(address);
	ft_strlcat(ptr, tmp, 15);
	free(tmp);
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

char	*ft_strcat_format(char *dest, char c, va_list list)
{
	char	*tmp;

	if (c == 'd' || c == 'i')
		return (is_int_format(dest, ft_ltoa((long)va_arg(list, int))));
	else if (c == 's')
	{
		tmp = va_arg(list, char *);		
		if (!tmp)
			return (ft_strcat(dest, "(null)"));
		return (ft_strcat(dest, tmp));
	}
	else if (c == 'c')
		return (strcat_one_char(dest, (unsigned char)va_arg(list, int)));
	else if (c == 37)
		return (strcat_one_char(dest, c));
	else if (c == 'u')
		return (is_int_format(dest, ft_ltoa((long)va_arg(list, unsigned int))));
	else if (c == 'x' || c == 'X')
		return (is_int_format(dest, by_uplow_hex(get_hexa((long)(va_arg(list, int))), c)));
	else if (c == 'p')
		return (get_adress(dest, va_arg(list, void *)));
	else
		return (invalid_format(dest, c));
}
