# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 16:53:33 by ldinaut           #+#    #+#              #
#    Updated: 2022/01/27 17:26:23 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long.a

SCRS	=	so_long.c \

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -lmlx -lXext -lX11

OBJS	=	$(SRCS:.c=.o)

$(NAME)	:

