/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 06:29:28 by yjirapin          #+#    #+#             */
/*   Updated: 2022/10/28 18:39:49 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"

# ifdef __linux__
#  define IS_LINUX 1
# else
#  define IS_LINUX 0
# endif

/*
unsigned int:
An unsigned integer is a 32-bit datum that encodes a
nonnegative integer in the range [0 to 4294967295].

unsigned long:
Unsigned long variables are extended size variables
for number storage, and store 32 bits (4 bytes).
Unlike standard longs unsigned longs won't store
negative numbers, making their range
from 0 to 4,294,967,295 (2^32 - 1).
*/

int		ft_printf(const char *str, ...);
int		ft_printme_percent(void);
int		ft_printme_c(char child);
int		ft_printme_str(char *sista);
int		ft_printme_digits(int gold);
int		ft_printme_hex(unsigned int number, char huh);
int		ft_printme_u(unsigned int figment);
int		ft_printme_p(unsigned long int birds);
#endif
