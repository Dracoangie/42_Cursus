# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 21:53:56 by angnavar          #+#    #+#              #
#    Updated: 2025/02/03 16:14:37 by angnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Directorios principales
SRC_DIR = src
INCLUDE_DIR = includes
LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
MINILIBX_DIR = includes/minilibx-linux

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MINILIBX_DIR)
MLX_FLAGS = -lX11 -lXext -lm

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJ)
		@echo "\033[0;34m"
		@echo "      :::::::::: :::::::::      :::      :::::::: ::::::::::: ::::::::  :::  "
		@echo "     :+:        :+:    :+:   :+: :+:   :+:    :+:    :+:    :+:    :+: :+:   "
		@echo "    +:+        +:+    +:+  +:+   +:+  +:+           +:+    +:+    +:+ +:+    "
		@echo "   :#::+::#   +#++:++#:  +#++:++#++: +#+           +#+    +#+    +:+ +#+     "
		@echo "  +#+        +#+    +#+ +#+     +#+ +#+           +#+    +#+    +#+ +#+      "
		@echo " #+#        #+#    #+# #+#     #+# #+#    #+#    #+#    #+#    #+# #+#       "
		@echo "###        ###    ### ###     ###  ########     ###     ########  ########## "
		@echo "\033[0m"
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME) $(MLX_FLAGS)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# ============================== COMPILACIÓN LIBRERÍAS ========================== #

$(LIBFT):
	@echo "📦 Compilando Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PRINTF):
	@echo "🖨️  Compilando ft_printf..."
	@$(MAKE) -s -C $(PRINTF_DIR)

$(MINILIBX):
	@echo "🚑  Compilando libmlx..."
	$(MAKE) -s -C $(MINILIBX_DIR)

# =========================== COMPILACIÓN DE ARCHIVOS ========================== #

%.o: %.c
	@echo "⚙️  Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# ================================ REGLAS DE LIMPIEZA =========================== #

clean:
	@echo "🧹 Limpiando archivos objeto..."
	$(MAKE) -s -C $(LIBFT_DIR) clean
	$(MAKE) -s -C $(PRINTF_DIR) clean
	$(MAKE) -s -C $(MINILIBX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@echo "🗑️  Eliminando ejecutable..."
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

# ============================== REGLAS ESPECIALES ============================== #

.PHONY: all clean fclean re

