#include "libftprintf.h"

static int	ft_hexlen(long n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	if (n >= 0)
	{
		while (n)
		{
			len++;
			n /= 16;
		}
	}
	else
		return (8);
	return (len);
}

static char	*get_negative_hexa(char	*ptr, long n)
{
	char	*hex;
	char	*tmp;
	int	i;
	int	len_ptr;

	hex = ft_strdup("0123456789abcdef");
	if (!hex)
		return (NULL);
	tmp = (char *)&n;
	tmp[4] = '\0';
	i = 3;
	len_ptr = 0;
	while (i >= 0 && len_ptr < 8)
	{
		ptr[len_ptr++] = hex[((unsigned char)tmp[i]) / 16];
		ptr[len_ptr++] = hex[((unsigned char)tmp[i]) % 16];
		i--;
	}
	free(hex);
	return (ptr);
}

char	*get_hexa(long n)
{
	char	*hex;
	char	*ptr;
	int	len;

	len = ft_hexlen(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len--] = '\0';
	if (n == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	hex = ft_strdup("0123456789abcdef");
	while (n > 0)
	{
		ptr[len--] = hex[n % 16];
		n /= 16;
	}
	free (hex);
	if(n == 0)
		return (ptr);
	return (get_negative_hexa(ptr, n));
}
