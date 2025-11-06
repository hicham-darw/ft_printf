/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:18:02 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/06 01:43:30 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list	args;
	va_list	tmp_args;
	int		ret;
	char	*string;

	if (!s)
		return (-1);
	va_start(args, s);
	va_copy(tmp_args, args);
	ret = get_len_printf(s, tmp_args);
	va_end(tmp_args);
	string = (char *)malloc(sizeof(char *) * (ret + 1));
	if (!string)
		return (-1);
	ft_memset(string, 0, ret + 1);
	if (!ft_get_string(string, s, args))
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	ret = write(1, string, ft_strlen(string));
	free(string);
	return (ret);
}
