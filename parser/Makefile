# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/04/24 23:43:51 by sgummy            #+#    #+#             #
#   Updated: 2022/04/24 23:43:51 by sgummy           ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

SRCS		= $(shell find . -name '*.c')

OBJS		:= $(SRCS:.c=.o)

LIBDIR		= ../libs/Libft
LIBFT_LIB	= $(LIBDIR)/libft.a
LIB			= -L$(LIBDIR) -lft

ifeq ($(shell uname), Linux)
MLXDIR		= ../libs/minilibx_linux
MLX			= $(MLXDIR)/libmlx_Linux.a
MLX_START	= -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else ifeq ($(shell uname), Darwin)
MLXDIR		= ../libs/minilibx_mms
MLX			= $(MLXDIR)/libmlx.dylib
MLX_START	= -lmlx -framework  OpenGL -framework AppKit
endif
NAME		= libparser.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f

%.o: %.c	cub3D.h Makefile ../render/render.h ../includes/main.h ../includes/structures.h
			$(CC) -DPWD="\"$(shell pwd)\"" -g -c $< -o $@
#  $(MLX_START) 
$(NAME):	 $(OBJS)
		ar rcs libparser.a $?

all:		$(NAME)

$(OBJS) : | $(LIBFT_LIB)

$(LIBFT_LIB): 
	cd $(LIBDIR) && $(MAKE) && $(MAKE)

$(MLX) :
	cd $(MLXDIR) && $(MAKE)

clean:
		$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
	
lib  : $(OBJS)
		ar rcs libparser.a $?

.PHONY:		all clean fclean re tools tools2 lib print
