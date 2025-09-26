# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glancell <glancell@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 23:20:38 by glancell          #+#    #+#              #
#    Updated: 2025/09/25 22:11:26 by glancell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = fdf
MLX      = libmlx_Linux.a
LIBFT    = libft.a
GNL      = get_next_line.a

LFT_PATH = ./libft/
MLX_PATH = ./mlx_linux/
GNL_PATH = ./get_next_line/
INCLUDES = ./include/
SRCDIR   = ./src/

SRC      = $(SRCDIR)main.c $(SRCDIR)parsing.c $(SRCDIR)parsing_uti.c $(SRCDIR)parsing_uti_2.c $(SRCDIR)parsing_uti_3.c \
           $(SRCDIR)drawing.c $(SRCDIR)drawing_uti.c $(SRCDIR)drawing_uti_2.c $(SRCDIR)drawing_uti_3.c \
		   $(SRCDIR)controls.c $(SRCDIR)menu.c $(SRCDIR)menu_uti.c  $(SRCDIR)controls_uti.c $(SRCDIR)controls_uti_2.c \
		   $(SRCDIR)close.c $(SRCDIR)key_press.c $(SRCDIR)utility.c

OBJ = objs/main.o objs/parsing.o objs/parsing_uti.o objs/parsing_uti_2.o objs/parsing_uti_3.o \
	  objs/drawing.o objs/drawing_uti.o objs/drawing_uti_2.o objs/drawing_uti_3.o \
	  objs/controls.o objs/menu.o objs/menu_uti.o objs/controls_uti.o objs/controls_uti_2.o \
	  objs/close.o objs/key_press.o objs/utility.o

CF       = -Wall -Wextra -Werror
CC       = cc
MLX_CF   = -lm -lbsd -lXext -lX11
CFI      = -I$(INCLUDES)

RM       = rm -f

all: libft gnl mlx $(NAME)

$(NAME): $(OBJ)
	@printf "Generating FdF executable...\n"
	$(CC) $(CF) -o $(NAME) $(OBJ) $(MLX_PATH)$(MLX) $(GNL_PATH)$(GNL) $(LFT_PATH)$(LIBFT) $(MLX_CF)
	@printf "Done!\n"

objs/%.o: $(SRCDIR)%.c
	@mkdir -p objs
	@printf "Compiling $<...\n"
	$(CC) $(CF) -g -c $(CFI) $< -o $@

libft:
	@make -C $(LFT_PATH)

gnl: libft
	@make -C $(GNL_PATH)

mlx:
	@make -C $(MLX_PATH) --quiet

clean:
	@printf "Cleaning object files...\n"
	$(RM) -rf objs $(NAME) $(GNL_PATH)$(GNL)

fclean: clean
	@printf "Cleaning all objects and libraries...\n"
	@make fclean -C $(LFT_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(GNL_PATH)
	@printf "All cleaned!\n"

re: fclean all
	@printf "Rebuilding everything...\n"

.PHONY: all clean fclean re libft gnl mlx
