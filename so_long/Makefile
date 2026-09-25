# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 16:57:42 by fasharif          #+#    #+#              #
#    Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =	utils/mov_dir_test.c utils/mov_dir.c utils/movement.c utils/render.c so_long.c \
		utils/split.c utils/test_maps.c utils/utils_test_maps.c utils/utils.c

OBJ = $(SRC:.c=.o)

MLX_DIR = ../minilibx
MLX = $(MLX_DIR)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

execute: $(NAME)
	./$(NAME) maps/map.ber

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all execute clean fclean re
