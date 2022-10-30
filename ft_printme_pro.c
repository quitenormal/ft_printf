/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printme_pro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:32:23 by yjirapin          #+#    #+#             */
/*   Updated: 2022/10/30 16:00:01 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*From manpage
Printing with o, u, x, X
The unsigned int argument is converted to unsigned octal (o),
unsigned decimal (u), or unsigned hexadecimal (x and X) notation.
The letters abcdef are used for x conversions;
the letters ABCDEF are used for X conversions.
*/

/* Printing the Units
'A' - 10 + number
15 - 10 = 5 = F
14 - 10 = 4 = E
13 - 10 = 3 = D
12 - 10 = 2 = C
11 - 10 = 1 = B
10 - 10 = 0 = A
'a' - 10 + number
15 - 10 = 5 = f
14 - 10 = 4 = e
13 - 10 = 3 = d
12 - 10 = 2 = c
11 - 10 = 1 = b
10 - 10 = 0 = a
Length will always be 1
*/

int	ft_printme_hex_unit(unsigned int tiny, char xxx)
{
	if (tiny < 10)
	{
		ft_putchar_fd('0' + tiny, 1);
	}
	else
	{
		if (xxx == 'X')
			ft_putchar_fd('A' - 10 + tiny, 1);
		else
			ft_putchar_fd('a' - 10 + tiny, 1);
	}
	return (1);
}

int	ft_printme_hex_driver(unsigned int number, char xxx)
{
	int	dudu;
	int	leftover;

	dudu = 0;
	if (number > 0)
	{
		leftover = number % 16;
		number = number / 16;
		dudu += ft_printme_hex_driver(number, xxx);
		dudu += ft_printme_hex_unit(leftover, xxx);
	}
	return (dudu);
}

//Check to see if null then terminate
//If zero then print 0 and len = 1

int	ft_printme_hex(unsigned int decimal, char xxx)
{
	int	longish;

	longish = 0;
	if (decimal == 0)
	{
		longish = ft_printme_hex_unit(0, xxx);
	}
	else
	{
		longish = ft_printme_hex_driver(decimal, xxx);
	}
	return (longish);
}
