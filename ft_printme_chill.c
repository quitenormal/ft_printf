/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printme_chill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:54:27 by yjirapin          #+#    #+#             */
/*   Updated: 2022/10/30 16:03:16 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*From manpage
Printing with o, u, x, X
The unsigned int argument is converted to unsigned octal (o),
unsigned decimal (u), or unsigned hexadecimal (x and X) notation.

For the %u option
Case 0: Printing positive unsigned decimal number
*/
/*Case 1: Printing char
Example: 'b' ft_print 98
--PASS--
Case 2: Print negative number
Example: -14 ft_print 4294967282
--PASS--

Had to change ft_putnbr_fd input from int to long int
in order to support numbers up to 4294967296;
*/

int	unsigned_int_len(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_printme_u(unsigned int u)
{
	int	length;

	length = unsigned_int_len(u);
	if (u > 0)
	{
		ft_putunsigned_int(u, 1);
	}
	else if (u == 0)
	{
		ft_putunsigned_int(u, 1);
	}
	return (length);
}
