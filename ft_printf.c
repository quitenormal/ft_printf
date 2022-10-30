/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 06:26:45 by yjirapin          #+#    #+#             */
/*   Updated: 2022/10/28 20:02:01 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/*
We need another function to use the charcter behind the %
symbol plus the variable name to figure out what to print.
*/

int	ft_goodforyou(va_list args, char anything)
{
	int	kwamlong;

	kwamlong = 0;
	if (anything == 'c')
		kwamlong += ft_printme_c(va_arg(args, unsigned int));
	else if (anything == 'X' || anything == 'x')
		kwamlong += ft_printme_hex(va_arg(args, int), anything);
	else if (anything == 's')
		kwamlong += ft_printme_str(va_arg(args, char *));
	else if (anything == 'u')
		kwamlong += ft_printme_u(va_arg(args, unsigned int));
	else if (anything == 'd' || anything == 'i')
		kwamlong += ft_printme_digits(va_arg(args, int));
	else if (anything == 'p')
		kwamlong += ft_printme_p(va_arg(args, unsigned long));
	else if (anything == '%')
		kwamlong += ft_printme_percent();
	return (kwamlong);
}
/*
ft_printf Requirement:
1. Keep track of length (to return as output)
2. Print out to fd (e.g. stdout)
ft_printf will alternatively
print coverted content and substring
one character at a time (while adding the number of characters
to the total length) until it reaches the end
of the original string.
*/

/*
A note about va_start(xxx, y):
In C, the va_start function initializes the variable
 argument list referred to by xxx after the first y.
 The va_start function must be called before
 using the va_arg function.
 The required header is #include <stdarg.h>.
 */

int	ft_printf(const char *str, ...)
{
	int			length;
	va_list		args;
	char		anything;

	va_start(args, str);
	length = 0;
	while (*str)
	{
		if (*str == '%')
		{
			anything = *(str + 1);
			length += ft_goodforyou(args, anything);
			str++;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			length++;
		}
		str++;
	}
	va_end(args);
	return (length);
}
