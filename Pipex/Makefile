# ============================ VARIABLES PRINCIPALES =========================== #

NAME        := pipex
NAME_BONUS  := pipex_bonus

# Directorios de código
SRC_DIR     := src
SRC_BONUS_DIR := src_bonus
INCLUDE_DIR := includes
LIBFT_DIR   := includes/libft
PRINTF_DIR  := includes/ft_printf

# Bibliotecas
LIBFT       := $(LIBFT_DIR)/libft.a
PRINTF      := $(PRINTF_DIR)/libftprintf.a

# Archivos fuente y objetos
SRC         := src/helper.c src/main.c src/pipex.c
OBJ         := $(SRC:.c=.o)

SRC_BONUS   := src_bonus/here_doc.c src_bonus/helper_bonus.c src_bonus/main_bonus.c src_bonus/pipex_bonus.c src_bonus/comands.c
OBJ_BONUS   := $(SRC_BONUS:.c=.o)

# Compilador y flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
		@echo "\033[0;34m"
		@echo "      ::::::::: ::::::::::: :::::::::  :::::::::: :::    ::: "
		@echo "     :+:    :+:    :+:     :+:    :+: :+:        :+:    :+:  "
		@echo "    +:+    +:+    +:+     +:+    +:+ +:+         +:+  +:+    "
		@echo "   +#++:++#+     +#+     +#++:++#+  +#++:++#     +#++:+      "
		@echo "  +#+           +#+     +#+        +#+         +#+  +#+      "
		@echo " #+#           #+#     #+#        #+#        #+#    #+#      "
		@echo "###       ########### ###        ########## ###    ###       "
		@echo "\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# ================================ REGLA BONUS ================================ #

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(PRINTF) $(OBJ_BONUS)
	@echo "\033[0;34m🚀 Compilando BONUS...\033[0m"
	@echo "\033[0;34m"
	@echo "      ::::::::: ::::::::::: :::::::::  :::::::::: :::    ::: "
	@echo "     :+:    :+:    :+:     :+:    :+: :+:        :+:    :+:  "
	@echo "    +:+    +:+    +:+ +:+    +:+ +:+         +:+  +:+  +:+    "
	@echo "   +#++:++#+     +#+     +#++:++#+  +#++:++#     +#++:+      "
	@echo "  +#+           +#+     +#+        +#+         +#+  +#+      "
	@echo " #+#           #+#     #+#        #+#        #+#    #+#      "
	@echo "###       ########### ###        ########## ###    ###       "
	@echo "\033[0m"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(PRINTF) -o $(NAME_BONUS)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación BONUS completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# ============================== COMPILACIÓN LIBRERÍAS ========================== #

$(LIBFT):
	@echo "📦 Verificando Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
	@echo "🖨️  Verificando ft_printf..."
	@$(MAKE) -s -C $(PRINTF_DIR) --no-print-directory

# =========================== COMPILACIÓN DE ARCHIVOS ========================== #

%.o: %.c
	@echo "⚙️  Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# ================================ REGLAS DE LIMPIEZA =========================== #

clean:
	@echo "🧹 Limpiando archivos objeto..."
	@$(MAKE) -s -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -s -C $(PRINTF_DIR) clean --no-print-directory
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@echo "🗑️  Eliminando ejecutables..."
	@$(MAKE) -s -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -s -C $(PRINTF_DIR) fclean --no-print-directory
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

# ============================== REGLAS ESPECIALES ============================== #

.PHONY: all bonus clean fclean re
