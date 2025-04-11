# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:08:31 by alde-abr          #+#    #+#              #
#    Updated: 2025/04/11 19:53:56 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -g3 #-Wall -Wextra -Werror -g3
MLXFLAGS = -lXext -lX11 -lm -Lminilibx-linux -lmlx_Linux
LIB = libft/libft.a
MLX = minilibx-linux/libmlx_Linux.a

SRC = \
	fdf.c mlx_utils.c mlx_setup.c draw_line.c parsing.c map_parsing.c

SRC_BONUS = \

INCLUDES = -Iincludes/ -Iminilibx/

SRC_DIR = src/
OBJ_DIR = obj/

all: $(NAME)

#Construction de la lib
$(LIB):
	make -C libft/

#Création des fichiers .o
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC)  $(INCLUDES) $(CFLAGS) -c $< -o $@

#Création du programme
$(NAME): $(MLX) $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLX) -Llibft -lXext -lX11 -lft -lm

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY = all clean fclean re
