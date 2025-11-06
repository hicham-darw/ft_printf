/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:56:49 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/06 05:30:59 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		get_len_printf(const char *s, va_list list);
char	*ft_decimal_cat(char *str, int nbr);
char	*ft_hexadecimal_cat(char *str, unsigned int nbr, char c);
char	*ft_strcat(char *dest, char *src);
char	*ft_charcat(char *str, char c);
char	*ft_address_cat(char *string, void *adress);
int		ft_printf(const char *s, ...);
char	*printf_not_completed(char *s);
char	*ft_uitoa(unsigned int n);
int		len_hexa(unsigned int nbr);
char	*ft_get_string(char *str, const char *frmt, va_list args);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
