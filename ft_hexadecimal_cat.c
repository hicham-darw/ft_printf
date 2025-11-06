/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_cat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 05:50:26 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/28 15:51:29 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*fill_buff_hexa(unsigned int nbr, int len, char c)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len--] = '\0';
	if (!nbr)
		ptr[len] = '0';
	while (nbr)
	{
		if (nbr % 16 < 10)
			ptr[len--] = (nbr % 16) + 48;
		else
		{
			if (c == 'X')
				ptr[len--] = (nbr % 16) + 55;
			else
				ptr[len--] = (nbr % 16) + 87;
		}
		nbr /= 16;
	}
	return (ptr);
}

char	*ft_hexadecimal_cat(char *dest, unsigned int nbr, char c)
{
	int		len;
	char	*ptr;

	if (!dest)
		return (NULL);
	len = len_hexa(nbr);
	ptr = fill_buff_hexa(nbr, len, c);
	ft_strcat(dest, ptr);
	free(ptr);
	return (dest);
}
