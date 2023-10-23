# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:53:33 by ldinaut           #+#    #+#              #
#    Updated: 2023/10/23 23:13:55 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS_FILES	=	so_long.c \
			checkmap.c \
			ft_printmap.c \
			ft_tab.c \
			init_data.c \
			events.c \
			move.c \
			put_move_img.c \
			colloc_rupee.c \
			ft_free_all.c \
			get_next_line.c \
			get_next_line_utils.c

INC_FILES	= so_long.h get_next_line.h

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

INCS	=	$(addprefix includes/, $(INC_FILES))

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

INCLUDES=	-I. -Iminilibx-linux/.

LIB		=	-Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft -Lft_printf -lftprintf

OBJS_FILES	=	$(SRCS_FILES:%.c=%.o)

OBJS	=		$(addprefix objs/, $(OBJS_FILES))

all		:	$(NAME)

$(NAME)	: $(OBJS)
		make -C libft
		make -C minilibx-linux
		make -C ft_printf
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

# %.o : %.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

objs/%.o	: srcs/%.c $(INCS)
	mkdir -p objs
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

clean	:
		rm -rf $(OBJS)
		make -C libft clean
		make -C minilibx-linux clean
		make -C ft_printf clean
		rm -rf $(OBJS) $(DEP)
		rm -rf objs/

fclean	:	clean
		rm -rf $(NAME)
		make -C libft fclean
		make -C ft_printf fclean

re		:	fclean all

.PHONY: all clean fclean re
