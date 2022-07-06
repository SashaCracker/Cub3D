# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/04/24 23:43:33 by sgummy            #+#    #+#             #
#   Updated: 2022/04/24 23:43:33 by sgummy           ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

APP 			= cub3D

SYSTEM 			:= $(shell uname)
SRCDIR 			:= ./render/
OBJDIR 			:= ./objs/
HEADERDIR		:= includes
PWD				:= $(shell pwd)

SRCS 			:= $(shell find $(SRCDIR) -name '*.c')
OBJS_2			:= ${addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o))}
HEADERS			:= ${shell find ./libs -name '*.h'}
SYSTEM			=  $(shell uname)

CFLAGS			= -Wall -Wextra -Werror
DEBUG			= -g -fsanitize=address
OPTIM			= -O2
INCLUDES		= -I./includes
CC				= gcc
ifeq ($(SYSTEM), Linux)
MLXLIB			= -L./libs/minilibx_linux -lmlx_Linux -lXext -lX11 -lm -lz
MLXDIR			= ./libs/minilibx_linux/
else ifeq ($(SYSTEM), Darwin)
MLXLIB			= -L./libs/minilibx_opengl -lmlx -framework OpenGL -lz -framework AppKit
MLXDIR			= ./libs/minilibx_opengl/
endif
LIB				= -L./libs/libft -lft
PARSERLIB		= -L./parser/ -lparser -I./parser
MAIN			= ./objs/main.o

$(OBJDIR)%.o : $(SRCDIR)%.c Makefile includes/main.h includes/structures.h parser/cub3D.h render/render.h
		$(CC) $(CFLAGS)  -g -DPWD="\"$(shell pwd)\"" -c $< -o $@

${APP} 	: Makefile $(OBJS_2)
		$(CC) $(CFLAGS) $(DEBUG) $(OBJS_2) $(PARSERLIB) $(MLXLIB) $(LIB) -o $(APP)

all : $(APP)

$(OBJS_2) : |  parser mlx $(OBJDIR)

$(OBJDIR) :  
		mkdir -p  $(OBJDIR)
		
mlx :
	cd $(MLXDIR) && $(MAKE)

parser :
	$(MAKE) -C ./parser

$(LIB) :
	$(MAKE) -C ./libs/libft

$(MAIN) :
	$(CC) $(CFLAGS) -g -c main.c -o $(MAIN)
	
re:			fclean all

clean	:
	$(MAKE) clean -C  ./parser
	$(MAKE) clean -C  ./libs/libft
	$(MAKE) clean -C  $(MLXDIR)

fclean	:
		rm -rf $(APP)
		rm -rf $(OBJDIR)
		$(MAKE) fclean -C  ./parser
		$(MAKE) fclean -C  ./libs/libft
		$(MAKE) clean -C  $(MLXDIR)

.PHONY	: all clean fclean re buildrepo print parser mlx
	
