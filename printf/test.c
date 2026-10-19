/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:18:15 by sywee             #+#    #+#             */
/*   Updated: 2026/01/27 17:01:03 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*s;
	int		ft_printftotal;
	int		printftotal;

	s = "Hehehaha";
	ft_printf("ft_printf: Hehehaha\n");
	printf("   printf: Hehehaha\n");
	
	ft_printftotal = ft_printf("ft_printf: %c, %s\n", '-', s);
	printftotal =       printf("   printf: %c, %s\n", '-', s);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);
	
	ft_printftotal = ft_printf("ft_printf: NULL %s NULL\n", NULL);
	printftotal =       printf("   printf: NULL %s NULL\n", (char *)NULL);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);	
	
	ft_printftotal = ft_printf("ft_printf: %d, %d\n", INT_MIN, INT_MAX);
	printftotal =       printf("   printf: %d, %d\n", INT_MIN, INT_MAX);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);

	ft_printftotal = ft_printf("ft_printf: %i, %i\n", INT_MIN, INT_MAX);
	printftotal =       printf("   printf: %i, %i\n", INT_MIN, INT_MAX);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);

	ft_printftotal = ft_printf("ft_printf: %u, %u\n", -1, INT_MAX);
	printftotal =       printf("   printf: %u, %u\n", -1, INT_MAX);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);

	ft_printftotal = ft_printf("ft_printf: %%\n");
	printftotal =       printf("   printf: %%\n");
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);

	ft_printftotal = ft_printf("ft_printf: %x, %X, %x, %X\n", 10, 13, NULL, -1);
	printftotal =       printf("   printf: %x, %X, %x, %X\n", 10, 13, (int)((long)NULL), -1);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);

	ft_printftotal = ft_printf("ft_printf: %p, %p\n", main, -1);
	printftotal =       printf("   printf: %p, %p\n", main, -1);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);

	ft_printftotal = ft_printf("ft_printf: %p\n", NULL);
	printftotal =       printf("   printf: %p\n", NULL);
	printf("ft_printf total: %d\n", ft_printftotal);
	printf("   printf total: %d\n", printftotal);

	ft_printftotal = ft_printf("ft_printf: %a\n");
}
/* // p
	TEST(1, print(" %p ", -1));
	TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
	TEST(7, print(" %p %p ", INT_MIN, INT_MAX));
	TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));

// x
	TEST(2, print(" %x ", -1));
	TEST(13, print(" %x ", -9));
	TEST(14, print(" %x ", -10));
	TEST(15, print(" %x ", -11));
	TEST(16, print(" %x ", -14));
	TEST(17, print(" %x ", -15));
	TEST(18, print(" %x ", -16));
	TEST(19, print(" %x ", -99));
	TEST(20, print(" %x ", -100));
	TEST(21, print(" %x ", -101));
	TEST(23, print(" %x ", INT_MIN));
	TEST(24, print(" %x ", LONG_MAX));
	TEST(26, print(" %x ", UINT_MAX));
	TEST(27, print(" %x ", ULONG_MAX));
	TEST(28, print(" %x ", 9223372036854775807LL));
	TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(31, print(" %x ", -42));
	
// mix
	TEST(1, print("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0)); */