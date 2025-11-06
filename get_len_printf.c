/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:18:14 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/06 05:02:30 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_decimal_len(int n, char c)
{
	char	*ptr;
	int		len;

	if (c == 'c')
		return (1);
	ptr = ft_itoa(n);
	if (!ptr)
		return (0);
	len = ft_strlen(ptr);
	free(ptr);
	return (len);
}

static int	ft_unsigned_len(unsigned int n, char c)
{
	char	*ptr;
	int		len;

	if (c == 'u')
	{
		ptr = ft_uitoa(n);
		if (!ptr)
			return (-1);
		len = ft_strlen(ptr);
		free(ptr);
		return (len);
	}
	return (len_hexa(n));
}

static int	ft_adress_len(void *p)
{
	(void)p;
	return (14);
}

static void	ft_count_format(const char *s, va_list args, int *counter)
{
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'd' || *s == 'i' || *s == 'c')
				*counter += ft_decimal_len(va_arg(args, int), *s);
			else if (*s == 'x' || *s == 'X' || *s == 'u')
				*counter += ft_unsigned_len(va_arg(args, unsigned int), *s);
			else if (*s == 'p')
				*counter += ft_adress_len(va_arg(args, void *));
			else if (*s == 's')
				*counter += ft_strlen(va_arg(args, char *));
			else if (*s == '%')
				*counter += 1;
			else if (!*s)
				break ;
			else
				*counter += 2;
		}
		else
			*counter += 1;
		if (*s)
			s++;
	}
}

int	get_len_printf(const char *s, va_list args)
{
	int	counter;

	if (!s || !args)
		return (-1);
	counter = 0;
	ft_count_format(s, args, &counter);
	return (counter);
}
