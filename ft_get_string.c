/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 00:57:17 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/06 05:09:47 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*get_unsigned(char *str, char c, unsigned int n)
{
	char	*tmp;

	if (!str)
		return (NULL);
	if (c == 'x' || c == 'X')
		return (ft_hexadecimal_cat(str, n, c));
	else if (c == 'c')
		return (ft_charcat(str, n));
	tmp = ft_uitoa(n);
	ft_strcat(str, tmp);
	free(tmp);
	return (str);
}

char	*ft_get_string(char *str, const char *fm, va_list args)
{
	while (*fm)
	{
		if (*fm == '%')
		{
			fm++;
			if (*fm == 'd' || *fm == 'i')
				ft_decimal_cat(str, va_arg(args, int));
			else if (*fm == 'x' || *fm == 'X' || *fm == 'u' || *fm == 'c')
				get_unsigned(str, *fm, va_arg(args, unsigned int));
			else if (*fm == 'p')
				ft_address_cat(str, va_arg(args, void *));
			else if (*fm == 's')
				ft_strcat(str, va_arg(args, char *));
			else if (*fm == '%')
				ft_charcat(str, '%');
			else if (!*fm)
				return (printf_not_completed(str));
			else
				ft_charcat(str, *(fm));
		}
		else
			ft_charcat(str, *(fm));
		fm++;
	}
	return (str);
}
