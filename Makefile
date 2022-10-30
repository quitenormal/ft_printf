# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjirapin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 19:14:19 by yjirapin          #+#    #+#              #
#    Updated: 2022/10/28 13:21:50 by yjirapin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  You can do it

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM 			= /bin/rm -f


LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= 	ft_printf.c \
				ft_printme.c \
				ft_printme_pro.c \
				ft_printme_chill.c \
				ft_printme_diva.c

# Get each of the src file one by one
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs	$(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

# make option -C changes directory
clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r *.o

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
