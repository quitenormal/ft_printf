/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:17:23 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/13 14:12:00 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

/* Main function for testing
The int data type is a 32-bit signed two's complement integer.
It has a minimum value of -2,147,483,648 and
a maximum value of 2,147,483,647 (inclusive).
An Int32 is stored in 32 bits, not 31 bits, and half of its range is taken
 by negative numbers. Out of the remaining range, you lose one value to zero,
leaving 2147483647 as the highest positive number. The range for an
Int32 is -2147483648 to 2147483647.
And remember that the highest-order bit does not represent 2^31.
It represents -(2^31). That means that a number represented in
binary as 32 ones translates to -1, which is correct.
Note that ft_putnbr_fd(2147483648,1) will get you -2147483648
because the largest possible int is 2147483647.

int main (void){
	int droid;

	ft_putnbr_fd(300,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(2147483648,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(-2147483640,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(-2147483647,1);
	ft_putchar_fd('\n',1);
	ft_putnbr_fd(-2147483648,1);
	ft_putchar_fd('\n',1);
	return(0);
}
*/

/* Dev notes:

The function ft_putnbr_fd will put your number to fd.
For the minimum number of int (-2147483648)
the number -2 is written first then 147483648.
Without this if condition, you get a bunch of ---- and
segmentation fault. (Note: -2147483647 is always OK.)

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

*/
