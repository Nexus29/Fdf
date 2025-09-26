# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glancell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 21:40:17 by glancell          #+#    #+#              #
#    Updated: 2025/03/03 18:13:15 by glancell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
SRC = get_next_line.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@printf "Building $(NAME)...\n"
	ar rcs $@ $^

%.o: %.c
	@printf "Compiling $<...\n"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "Cleaning object files...\n"
	rm -f $(OBJ)

fclean: clean
	@printf "Removing $(NAME)...\n"
	rm -f $(NAME)

re: fclean all
	@printf "Rebuilding $(NAME)...\n"

.PHONY: all clean fclean re
