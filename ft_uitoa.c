/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:14:22 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/30 22:36:04 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ui_len(unsigned int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		i += 1;
		n /= 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ptr;
	size_t	len;

	len = ui_len(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
	{
		ptr[0] = 48;
		return (ptr);
	}
	while (n)
	{
		ptr[len - 1] = (n % 10) + 48;
		len--;
		n /= 10;
	}
	return (ptr);
}
