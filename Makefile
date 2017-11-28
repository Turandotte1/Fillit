# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 20:14:44 by mrychkov          #+#    #+#              #
#    Updated: 2017/05/17 16:30:28 by mrychkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colours

NO_COLOR = \033[0m
WAIT_COLOR = \033[1;33m
OK_COLOR = \033[1;32m
CLEAN_COLOR = \033[1;36m

# compiliation

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# files

SRC = main.c \
ft_reader.c \
ft_checker.c \
ft_map.c \
ft_store.c \
ft_place.c \
#ft_solve.c \

OBJ = $(SRC:.c=.o)

INC = -I ./libft/ -L ./libft -lft

# rules

.PHONY: all clean fclean re

all: $(NAME) 

$(NAME): $(OBJ)
	@make all -C libft
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $@ 
	@echo "$(OK_COLOR)	--- Fillit  created! ---	$(NO_COLOR)"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
	@echo "$(OK_COLOR)	--- Binary created   ---	$(NO_COLOR)"

norme:
	@norminette $(SRC) $(INC)
clean:
	rm -rf $(OBJ)
	@make clean -C libft
	@echo "$(CLEAN_COLOR)	--- Binary   deleted ---		$(NO_COLOR)"
	
fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)
	@echo "$(CLEAN_COLOR)	--- Program  deleted ---		$(NO_COLOR)"

re: fclean all
