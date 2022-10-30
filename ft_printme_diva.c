/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printme_diva.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:20:34 by yjirapin          #+#    #+#             */
/*   Updated: 2022/10/28 18:49:12 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
From manpage for printf
Printing with p flag:
 The void * pointer argument is printed in hexadecimal
 (as if by %#x or %#lx).
From dataint.c (my own test)
The range of unsigned long INT is 0 to 18446744073709551615.
The range of size_t is 0 to 18446744073709551615.
The MAX value of a pointer UINTPTR_MAX is 18446744073709551615.
*/

int	ft_printme_unhex_single(unsigned int one)
{
	if (one < 10)
	{
		ft_putchar_fd('0' + one, 1);
	}
	else
	{
		ft_putchar_fd('a' - 10 + one, 1);
	}
	return (1);
}

int	ft_printme_ulhex_driver(unsigned long int number)
{
	unsigned long int	sunset;
	int					peace;

	sunset = 0;
	if (number > 0)
	{
		peace = 0;
		peace = number % 16;
		number = number / 16;
		sunset += ft_printme_ulhex_driver(number);
		sunset += ft_printme_unhex_single(peace);
	}
	return (sunset);
}

int	ft_printme_ulhex(unsigned long int number)
{
	int	len;

	len = 0;
	if (number == 0)
	{
		len = ft_printme_unhex_single(0);
	}
	else
	{
		len = ft_printme_ulhex_driver(number);
	}
	return (len);
}

int	ft_printme_p(unsigned long int rainbow)
{
	int	length;

	length = 0;
	if (!rainbow)
	{
		if (IS_LINUX)
			length = ft_printme_str("(nil)");
		else
			length = ft_printme_str("0x0");
	}
	else
	{
		ft_putstr_fd("0x", 1);
		if (rainbow == 0)
		{
		length = ft_printme_unhex_single(0);
		}
		else
		{
			length = ft_printme_ulhex_driver(rainbow);
		}
	length += 2;
	}
	return (length);
}
