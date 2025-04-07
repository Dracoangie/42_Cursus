# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/21 16:44:04 by angnavar          #+#    #+#              #
#    Updated: 2025/03/06 15:23:27 by angnavar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Archivos fuente y objetos
SRC = src/Philo.c src/main.c src/Checker.c src/Helper.c src/Philos_act.c src/Philo_thread.c src/Monitor_philos.c
OBJ = $(SRC:.c=.o)

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ================================ REGLA PRINCIPAL ============================= #

all: $(NAME)

$(NAME):  $(OBJ)
		@echo "\033[0;34m"
		@echo "      :::::::::  :::    ::: ::::::::::: :::        :::::::: "
		@echo "     :+:    :+: :+:    :+:     :+:     :+:       :+:    :+: "
		@echo "    +:+    +:+ +:+    +:+     +:+     +:+       +:+    +:+  "
		@echo "   +#++:++#+  +#++:++#++     +#+     +#+       +#+    +:+   "
		@echo "  +#+        +#+    +#+     +#+     +#+       +#+    +#+    "
		@echo " #+#        #+#    #+#     #+#     #+#       #+#    #+#     "
		@echo "###        ###    ### ########### ########## ########       "
		@echo "\033[0m"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilación completada. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# =========================== COMPILACIÓN DE ARCHIVOS ========================== #

$(OBJ): %.o: %.c Philo.h
	@echo "⚙️  Compilando $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# ================================ REGLAS DE LIMPIEZA =========================== #

clean:
	@echo "🧹 Limpiando archivos objeto..."
	@rm -f $(OBJ)

fclean: clean
	@echo "🗑️  Eliminando ejecutable..."
	@rm -f $(NAME)

re: fclean all

# ============================== REGLAS ESPECIALES ============================== #

.PHONY: all clean fclean re




