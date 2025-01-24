# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armeyer <armeyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 12:33:03 by armeyer           #+#    #+#              #
#    Updated: 2025/01/15 12:07:42 by armeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		parsing.c \
		parsing_routines.c \
		parsing_texture_color_res.c \
		map.c \
		map_closure_check.c \
		parsing_utils.c \
		keys_manager.c \
		raycasting_init.c \
		raycasting_utils.c \
		raycasting_movement.c \
		raycasting.c \
		error_manager.c \
		get_next_line.c \
		get_next_line_2.c \
		get_next_line_utils.c \
		get_next_line_utils_2.c \
		init.c		\
		init_utils.c

NAME = Cub3D

MLX_DIR = minilibx-linux
MLX = libmlx.a 
CC = clang

CFLAGS = -Wall -Wextra -Werror -g

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}
all:
	make -C minilibx-linux
	$(MAKE) $(NAME)
	
$(NAME): $(OBJ)
	${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L$(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@echo $(NAME) : Created !

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj deleted"

fclean:	clean
	@rm -rf $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re, mlx

-include $(DPD)
