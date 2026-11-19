/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:58 by sywee             #+#    #+#             */
/*   Updated: 2026/01/27 16:59:33 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_number(va_list *my_list, char flag)
{
	int				count;
	int				number;
	unsigned int	u_number;

	count = 0;
	if (flag == 'd' || flag == 'i')
	{
		number = va_arg(*my_list, int);
		count += ft_signednbr(number);
	}
	else if (flag == 'u' || flag == 'x' || flag == 'X' || flag == 'p')
	{
		u_number = va_arg(*my_list, unsigned int);
		if (flag == 'u')
			count += ft_unsignednbr(u_number);
		else if (flag == 'X')
			count += ft_puthex(u_number, 1);
		else if (flag == 'x')
			count += ft_puthex(u_number, 0);
	}
	return (count);
}

static int	handle_pointer(va_list *my_list)
{
	void	*ptr;
	int		count;

	ptr = va_arg(*my_list, void *);
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_putptr(ptr);
	return (count);
}

int	handle_flag(va_list *my_list, char flag)
{
	char			c;
	char			*s;
	int				count;

	count = 0;
	if (flag == 'c')
	{
		c = va_arg(*my_list, int);
		count += ft_putchar(c);
	}
	else if (flag == 's')
	{
		s = va_arg(*my_list, char *);
		count += ft_putstr(s);
	}
	else if (flag == '%')
		count += ft_putchar('%');
	else if (flag == 'u' || flag == 'x' || flag == 'X' || flag == 'i'
		|| flag == 'd')
		count += handle_number(my_list, flag);
	else if (flag == 'p')
		count += handle_pointer(my_list);
	else if (flag == 'a')
		count += ft_putstr("HI I AM HUNGRYYYYYY");
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	my_list;
	int		i;
	int		count;

	va_start(my_list, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_flag(&my_list, format[i]);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(my_list);
	return (count);
}
/* msb -> signed bit

1XXXXXXX XXXXXXXX XXXXXXXX XXXXXXXX

00000000 00000000 00000000 00000001  --> 1
10000000 00000000 00000000 00000001  --> -1

Signed Int (32 Bit)
-2147483648 ~ 2147483647

Unsigned Int (32 Bit)
0 ~ 4294967295 */