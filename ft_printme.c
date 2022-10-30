/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 06:35:31 by yjirapin          #+#    #+#             */
/*   Updated: 2022/10/30 15:59:28 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* The length of the percentage sign
is always one.
*/

int	ft_printme_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

/* The length for ft_printme_c
is always one.
*/

int	ft_printme_c(char ss)
{
	ft_putchar_fd(ss, 1);
	return (1);
}

/* The length for ft_printme_str
is always going to be the string length.
*/

int	ft_printme_str(char *hey)
{
	if (!hey)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(hey, 1);
	return (ft_strlen(hey));
}

int	ft_printme_digits(int gg)
{
	ft_putnbr_fd(gg, 1);
	return (ft_len(gg));
}
