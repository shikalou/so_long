# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:53:33 by ldinaut           #+#    #+#              #
#    Updated: 2022/01/28 14:55:30 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	so_long.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

INCLUDES=	-I. -Iminilibx-linux/.

LIB		=	-Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft

OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	: $(OBJS) libft mlx
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

libft	:
		make -C libft

mlx	:
		make -C minilibx-linux

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean	:
		rm -rf $(OBJS)
		make -C libft clean
		make -C minilibx-linux clean

fclean	:	clean
		rm -rf $(NAME)
		make -C libft fclean

re		:	fclean all

.PHONY: all clean fclean re libft
