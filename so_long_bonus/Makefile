# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasharif <fasharif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 17:00:52 by fasharif          #+#    #+#              #
#    Updated: 2023/06/14 17:03:32 by fasharif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC =	utils_b/mov_dir_test.c utils_b/mov_dir.c utils_b/movement.c utils_b/render.c so_long.c \
		utils_b/split.c utils_b/test_maps.c utils_b/utils_test_maps.c utils_b/utils.c \
		utils_b/dir_test_en.c utils_b/utils_b.c utils_b/test_map_en_move.c utils_b/mov_en.c

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
