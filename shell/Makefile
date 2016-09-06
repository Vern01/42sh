# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/26 11:56:18 by sasiedu           #+#    #+#              #
#    Updated: 2016/09/06 10:00:31 by sasiedu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC = history.c keys_arrow.c keys_extra.c keys.c keys_ctrl.c keys_line.c \
	  new_main.c line_utils.c quotes.c shell_main.c tools.c

BIN = $(SRC:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I ../libft/ -c $(SRC)

clean:
	@rm -rf $(BIN)

re: fclean all
