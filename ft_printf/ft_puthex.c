/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:59:52 by sywee             #+#    #+#             */
/*   Updated: 2026/01/27 16:38:59 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(unsigned long n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long n, int upper_case)
{
	char	*hex_string;
	char	*preset_string;
	int		index;
	int		remainder;

	if (n == 0)
		return (ft_putchar('0'), 1);
	index = (count_digit(n));
	preset_string = "0123456789ABCDEF";
	if (!upper_case)
		preset_string = "0123456789abcdef";
	hex_string = malloc(index + 1);
	if (!hex_string)
		return (0);
	hex_string[index--] = '\0';
	while (index >= 0)
	{
		remainder = n % 16;
		n = n / 16;
		hex_string[index] = preset_string[remainder];
		index--;
	}
	ft_putstr(hex_string);
	index = ft_strlen(hex_string);
	return (free(hex_string), index);
}

int	ft_putptr(void	*ptr)
{
	return (ft_puthex((unsigned long) ptr, 0));
}

// int	main(void)
// {
// 	printf("%s\n", ft_puthex(15, 1));
// 	printf("%s\n", ft_puthex(16, 0));
// 	printf("%s\n", ft_puthex(1234, 1));
// }

// 20 / 16 = 1
// 20 % 16 = 4
// 	14

// 16 / 16 = 1
// 16 % 16 = 0
// 10

// 123 / 16 = 7
// 123 % 16 = 11

// 1234 / 16 = 77
// 1234 % 16 = 2
// 	___2
// 77 / 16 = 4
// 77 % 16 = 13
// 	_4D2

// dec = 1234;

// hex_len = count_hex_digt(dec);
// hex_str = malloc(hex_len + 1);
// hex_str[hex_len] = '\0';

// if (upper_case == 1)
// hex_chars = "0123456789ABCDEF";
// else
// hex_chars = "0123456789abcdef";

// hex_len--;
// while (hex_len > 15)
// {
// 	dec = dec / 16;
// 	remainder = (dec % 16);
// 	// Method 1
// 	// remainder = 0-9
// 	/* hex_char = remainder + '0';
// 	if remainder = 10
// 	hex_char = 'A'
// 	hex_str[hex_len] = hex_char; */
// 	// Method 2
// 	hex_str[hex_len] = hex_chars[remainder];

// 	// Method 3
// 	hex_str[hex_len] = get_hex_char(remainder);
// 	hex_len--;
// }

// get_hex_char(int n, int upper_case)
// if 0-9
// 	return (n + '0')

// if 10
// 	if uppercase return 'A';
// 	else return 'a';
// if 11 return 'B';