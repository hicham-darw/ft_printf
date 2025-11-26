/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:22:17 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/25 11:26:34 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_everything(va_list list, const char *s, int *ret)
{
	t_flags	flags;

	while (*s)
	{
		i = 0;
		if (*s == '%')
		{
			s = ft_initial_flags(++s, &flags);
			if (!s)
				return (0);
			ft_putargs(list, flags, *s, ret);

		}
		else
			*ret += write(1, s, 1);
		s++;
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		ret;

	if (!s || write(1, "", 0) < 0)
		return (-1);
	va_start(list, s);
	ret = 0;
	if (!ft_put_everything(list, s, &ret))
	{
		va_end(list);
		return (-1);
	}
	va_end(list);
	return (ret);
}
