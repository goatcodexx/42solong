/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:12:55 by sywee             #+#    #+#             */
/*   Updated: 2026/01/27 16:37:11 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// ft_printf.c
int		ft_printf(const char *format, ...);

// ft_printf_utils.c
int		ft_strlen(char	*str);

// ft_putstr.c
int		ft_putstr(char	*str);

// ft_putchar.c
int		ft_putchar(char c);

// ft_putnbr.c
int		ft_signednbr(int n);
int		ft_unsignednbr(unsigned int n);

// ft_puthex.c
int		ft_puthex(unsigned long n, int upper_case);
int		ft_putptr(void	*ptr);

#endif
