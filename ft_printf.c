/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:22:17 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/28 01:36:15 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_everything(va_list list, const char *s, int *ret)
{
	t_flags	flags;

	while (*s)
	{
		if (*s == '%')
		{
			s = ft_initial_flags((char *)++s, &flags);
			// printf("hashtag: %d\n", flags.hashtag);
			// printf("space:   %d\n", flags.space);
			// printf("plus :   %d\n", flags.plus);
			// printf("minus:   %d\n", flags.minus);
			// printf("zero:    %d\n", flags.zero);
			// printf("width:   %d\n", flags.width);
			// printf("prcson;%d\n", flags.precision);
			// return (0);
			if (!s)
				return (-1);
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

	if (!s)
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
