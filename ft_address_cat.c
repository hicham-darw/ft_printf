/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address_cat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:51:32 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/29 02:35:32 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*get_address(char *dest, char *src, unsigned long nbr, int len_nbr)
{
	if (!dest || !src)
		return (dest);
	src[len_nbr--] = '\0';
	while (nbr)
	{
		if ((nbr % 16) < 10)
			src[len_nbr--] = (nbr % 16) + 48;
		else
			src[len_nbr--] = (nbr % 16) + 87;
		nbr /= 16;
	}
	ft_strcat(dest, src);
	free(src);
	return (dest);
}

char	*ft_address_cat(char *dest, void *addr)
{
	int				len_nbr;
	unsigned long	nbr;
	unsigned long	tmp_nbr;
	char			*ptr;

	if (!dest)
		return (dest);
	if (!addr)
		return (ft_strcat(dest, "(nil)"));
	nbr = (unsigned long)addr;
	tmp_nbr = nbr;
	len_nbr = 0;
	while (tmp_nbr)
	{
		len_nbr++;
		tmp_nbr /= 16;
	}
	ptr = (char *)malloc(sizeof(char) * (len_nbr + 1 + 2));
	if (!ptr)
		return (NULL);
	ft_strcat(ptr, "0x");
	return (get_address(dest, ptr, nbr, len_nbr + 2));
}
