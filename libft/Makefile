# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:16:24 by alde-abr          #+#    #+#              #
#    Updated: 2025/03/06 13:10:07 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SB_S = dir_string_builder
PF_S = dir_printf

SRC = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
	ft_toupper.c ft_putstr.c ft_putchar.c ft_convert_base.c \
	ft_putbits.c ft_strrnchr.c ft_intcomp.c ft_strlowcase.c \
	ft_strupcase.c ft_digitcount.c ft_putnbr.c ft_atoi_base.c \
	ft_digitcount_base.c ft_strupcase.c ft_abs.c ft_get_next_line.c \
	ft_strcmp.c \
	\
	$(SB_S)/ft_string_builder.c $(SB_S)/ft_string_builder_utils.c \
	\
	$(PF_S)/ft_parseformat.c $(PF_S)/ft_pfbuildchar.c $(PF_S)/ft_pfbuildhexa.c \
	$(PF_S)/ft_pfbuildnb.c $(PF_S)/ft_pfbuildptr.c $(PF_S)/ft_pfbuildstr.c \
	$(PF_S)/ft_pfbuildunsnb.c $(PF_S)/ft_pfnullcheck.c $(PF_S)/ft_printf.c \
	$(PF_S)/ft_ui64convert_base.c $(PF_S)/ft_ui64atoi_base.c $(PF_S)/ft_ui64itoa.c

BONUS = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

INCLUDES = -Iincludes/

SRC_DIR = src/

OBJ_DIR = obj/

all: $(NAME)

#Création des fichiers .o
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_BONUS = $(BONUS:.c=.o)

#Création du dossier OBJ_DIR
$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SB_S)
	mkdir -p $(OBJ_DIR)/$(PF_S)

#Compilation de la lib
$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

#Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus : $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

test: bonus
	cc -g3 main.c libft.a
	valgrind ./a.out

.PHONY = all clean fclean re bonus
