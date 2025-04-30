# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:08:31 by alde-abr          #+#    #+#              #
#    Updated: 2025/04/30 13:55:11 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
MLXFLAGS = -lXext -lX11 -lm -Lminilibx-linux -lmlx_Linux
LIB = libft/libft.a
MLX = minilibx-linux/libmlx_Linux.a

PRS = parsing
IPT = input
UI = ui
MYMLX = my_mlx

SRC = \
	fdf.c \
	debug.c display_points.c color_utils.c \
	projection.c camera.c camera_utils.c \
	rotation.c color_map.c camera_stgs.c \
	\
	$(PRS)/map_parsing.c $(PRS)/map_checker.c $(PRS)/map_adapt.c \
	$(PRS)/point_parsing.c \
	\
	$(IPT)/input_offset.c $(IPT)/input_scale.c $(IPT)/input_render.c \
	$(IPT)/input.c $(IPT)/input_utils.c $(IPT)/input_rotation1.c \
	$(IPT)/input_rotation2.c $(IPT)/input_show_tri.c \
	$(IPT)/input_height.c $(IPT)/input_color.c\
	\
	$(UI)/draw_fdf_box.c $(UI)/draw_fdf_txt.c $(UI)/ui_setup.c \
	$(UI)/ui_utils.c \
	\
	$(MYMLX)/mlx_utils.c $(MYMLX)/mlx_setup.c $(MYMLX)/draw_rect.c \
	$(MYMLX)/draw_line.c $(MYMLX)/draw_filled_rect.c

SRC_BONUS = \

INCLUDES = -Iincludes/ -Iminilibx/

SRC_DIR = src/
OBJ_DIR = obj/

all: $(NAME) $(OBJ_DIR)

#Construction de la lib
$(LIB):
	make -C libft/

$(MLX):
	make -C minilibx-linux/

#Création des fichiers .o
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(PRS)
	mkdir -p $(OBJ_DIR)/$(IPT)
	mkdir -p $(OBJ_DIR)/$(UI)
	mkdir -p $(OBJ_DIR)/$(MYMLX)

#Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC)  $(INCLUDES) $(CFLAGS) -c $< -o $@

#Création du programme
$(NAME): $(MLX) $(LIB) $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLX) -Llibft -lXext -lX11 -lft -lm

clean:
	rm -f $(OBJ)
	make clean -C libft/
	make clean -C minilibx-linux/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
	make clean -C minilibx-linux/

re: fclean all

.PHONY = all clean fclean re
