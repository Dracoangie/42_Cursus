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

NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
      ft_strlen.c ft_strlcpy.c ft_atoi.c ft_strlcat.c ft_memset.c ft_memcpy.c \
      ft_bzero.c ft_memmove.c ft_strncmp.c ft_toupper.c ft_tolower.c \
      ft_strrchr.c ft_strchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
      ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
      ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putnbr_fd.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
            ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c \
            ft_lstiter_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus:
	make SRC="$(SRC) $(BONUS_OBJ)"

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus