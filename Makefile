# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 21:53:56 by angnavar          #+#    #+#              #
#    Updated: 2024/10/05 16:50:29 by angnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Nombre del ejecutable final
NAME = main_program

# Directorios principales
SRC_DIR = src
INCLUDE_DIR = includes
LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
MINILIBX_DIR = includes/minilibx-linux

# Archivos generados por las librerías
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

# Archivos fuente y objeto del programa principal
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR)

# Flags de enlace para MiniLibX (en Linux)
MLX_FLAGS = -lX11 -lXext -lm

# Regla principal
all: $(NAME)

# Compilar el programa principal
$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME) $(MLX_FLAGS)

# Compilar la biblioteca libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar la biblioteca ft_printf
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Compilar MiniLibX
$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

# Regla para compilar archivos fuente del proyecto principal
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos objeto
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean
	rm -f $(OBJ)

# Regla para limpiar completamente
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

# Regla para recompilar todo
re: fclean all

.PHONY: all clean fclean re

