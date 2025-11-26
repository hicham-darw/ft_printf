/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:56:49 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/25 11:04:38 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_flags
{
	int	hashtag;
	int	space;
	int	plus;
	int	minus;
	int	zero;
}t_flags;

int	ft_printf(const char *s, ...);

#endif
