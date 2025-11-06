/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_not_completed.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:28:23 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/30 23:15:07 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*printf_not_completed(char *str)
{
	if (!str)
		return (NULL);
	write(1, str, ft_strlen(str));
	free(str);
	str = NULL;
	return (NULL);
}
