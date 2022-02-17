# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:53:33 by ldinaut           #+#    #+#              #
#    Updated: 2022/02/17 17:40:35 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	so_long.c \
			checkmap.c \
			ft_tab.c \
			init_data.c \
			events.c \
			move.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g

INCLUDES=	-I. -Iminilibx-linux/.

LIB		=	-Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft

OBJS	=	$(SRCS:%.c=%.o)

all		:	$(NAME)

$(NAME)	: $(OBJS)
		make -C libft
		make -C minilibx-linux
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean	:
		rm -rf $(OBJS)
		make -C libft clean
		make -C minilibx-linux clean

fclean	:	clean
		rm -rf $(NAME)
		make -C libft fclean
		make -C minilibx-linux clean

re		:	fclean all

.PHONY: all clean fclean re
