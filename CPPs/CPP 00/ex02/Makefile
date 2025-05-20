# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 10:57:18 by angnavar          #+#    #+#              #
#    Updated: 2025/04/21 18:47:59 by angnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

# Directorios
OBJ_DIR = obj

# Nombres base de los archivos fuente
SRC = Account.cpp tests.cpp

# Archivos fuente y objetos (con rutas)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

# Compilador y flags
CC = c++
RM = rm -f
RMDIR = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;34m"
	@echo "  _____        ___ ___  " 
	@echo " |   __|_ _   |   |_  |" 
	@echo " |   __|_'_|  | | |  _|" 
	@echo " |_____|_,_|  |___|___|" 
	@echo "\033[0m"
	@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# =========================== COMPILACIÓN DE ARCHIVOS ========================== #

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;34m⚙️  Compilando $<...\033[0m"
	@$(CC) $(CPPFLAGS) -c $< -o $@

# ================================ REGLAS DE LIMPIEZA =========================== #

clean:
	@echo "\033[0;35m🧹 Limpiando archivos objeto...\033[0m"
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@echo "\033[0;35m🗑️  Eliminando ejecutable...\033[0m"
	@$(RM) $(NAME)

re: fclean all

run: all
	@echo "\033[0;36m🚀 Ejecutando programa...\033[0m"
	@./$(NAME)

.PHONY: all clean fclean re run

