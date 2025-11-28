/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:56:49 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/28 01:14:54 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
/*
*/
# include <stdio.h>
typedef	struct	s_flags
{
	int	hashtag;
	int	space;
	int	plus;
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	(*call_back)(struct s_flags *, va_list, int c);
}t_flags;

int	ft_printf(const char *s, ...);
int	ft_isformat(char c);
char	*ft_initial_flags(char *s, t_flags *flags);
int	ft_putargs(va_list list, t_flags flags, char c, int *ret);

#endif
