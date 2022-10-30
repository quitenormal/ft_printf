# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 19:25:17 by yjirapin          #+#    #+#              #
#    Updated: 2022/10/30 15:49:24 by yjirapin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile for libft
#
# If not using the Makefile for libft, you can just use
# gcc ft_printme.c ft_printf.c ... -Llibft -lft

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB	 = ar -rcs
RM = /bin/rm -f
SRC_DIRS = ./

SRCS =	ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putunsigned_int.c \
		ft_strlen.c \
		ft_len.c


OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs	$(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build

clean:
	$(RM) -r *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
