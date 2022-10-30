/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:12:16 by yjirapin          #+#    #+#             */
/*   Updated: 2022/03/11 22:14:48 by yjirapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* main function


int main(void) {
	unsigned char mama;
	size_t	papa;

	mama = 'w';
	papa = 1;
	ft_putchar_fd(mama, papa);
}
*/
