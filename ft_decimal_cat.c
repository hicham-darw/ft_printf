/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_cat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 05:42:14 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/29 02:52:06 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_decimal_cat(char *str, int dec)
{
	char	*ptr;

	if (!str)
		return (NULL);
	ptr = ft_itoa(dec);
	if (!ptr)
		return (NULL);
	ft_strcat(str, ptr);
	free(ptr);
	return (str);
}
