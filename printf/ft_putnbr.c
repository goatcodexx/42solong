/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sywee <sywee@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:00:05 by sywee             #+#    #+#             */
/*   Updated: 2026/01/27 15:34:16 by sywee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(long n)
{
	int		count;

	count = 1;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_signednbr(int n)
{
	int		result_index;
	char	*result;
	long	num;

	num = n;
	result_index = count_digit(num);
	if (n < 0)
		num = num * -1;
	result = malloc(result_index + 1);
	if (!result)
		return (0);
	result[result_index] = '\0';
	while (result_index > 0)
	{
		result[result_index - 1] = num % 10 + '0';
		num = num / 10;
		result_index--;
	}
	if (result_index == 0 && n < 0)
		result[result_index] = '-';
	ft_putstr(result);
	free(result);
	return (count_digit(n));
}

int	ft_unsignednbr(unsigned int n)
{
	int		result_index;
	char	*result;

	result_index = count_digit(n);
	result = malloc(result_index + 1);
	if (!result)
		return (0);
	result[result_index] = '\0';
	while (result_index > 0)
	{
		result[result_index - 1] = n % 10 + '0';
		n = n / 10;
		result_index--;
	}
	ft_putstr(result);
	result_index = ft_strlen(result);
	free(result);
	return (result_index);
}

/* int	main(void)
{
	printf("%s\n", ft_signednbr(123545454));
	printf("%s\n", ft_signednbr(-1));
	printf("%s\n", ft_signednbr(-123));
	printf("%s\n", ft_signednbr(INT_MIN));
	printf("%s\n", ft_signednbr(INT_MAX));

	printf("%s\n", ft_unsignednbr(123545454));
	printf("%s\n", ft_unsignednbr(-1));
	printf("%s\n", ft_unsignednbr(-123));
	printf("%s\n", ft_unsignednbr(INT_MIN));
	printf("%s\n", ft_unsignednbr(INT_MAX));

	// printf("%d %i %u\n", 2147483648, 2147483648, 2147483648);
	// printf("%d %i %u\n", UINT_MAX, UINT_MAX, UINT_MAX);
} */