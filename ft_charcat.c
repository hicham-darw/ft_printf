/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:09:00 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/27 11:10:41 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_charcat(char *dest, char c)
{
	int	i;

	if (!dest)
		return (NULL);
	i = 0;
	while (dest[i])
		i++;
	dest[i++] = c;
	dest[i] = '\0';
	return (dest);
}
