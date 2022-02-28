# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:53:33 by ldinaut           #+#    #+#              #
#    Updated: 2022/02/28 14:07:44 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	srcs/so_long.c \
			srcs/checkmap.c \
			srcs/ft_printmap.c \
			srcs/ft_tab.c \
			srcs/init_data.c \
			srcs/events.c \
			srcs/move.c \
			srcs/put_move_img.c \
			srcs/colloc_rupee.c \
			srcs/ft_free_all.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g

INCLUDES=	-I. -Iminilibx-linux/.

LIB		=	-Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft -Lft_printf -lftprintf

OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	: $(OBJS)
		make -C libft
		make -C minilibx-linux
		make -C ft_printf
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean	:
		rm -rf $(OBJS)
		make -C libft clean
		make -C minilibx-linux clean
		make -C ft_printf clean

fclean	:	clean
		rm -rf $(NAME)
		make -C libft fclean
		make -C ft_printf fclean

re		:	fclean all

.PHONY: all clean fclean re
