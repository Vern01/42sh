# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/26 11:56:18 by sasiedu           #+#    #+#              #
#    Updated: 2016/09/09 16:35:12 by sasiedu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC = history.c keys_arrow.c keys_extra.c keys.c keys_ctrl.c keys_line.c \
	  new_main.c line_utils.c quotes.c shell_main.c tools.c \
	  .auto_complete.c auto_complete_tools.c \
	  .auto_complete_read.c ft_lstsize.c auto_complete_print.c \
	  keys_ctrl_tools.c keys_line1.c keys_shift.c copy_cut_paste.c \
	  copy_tools.c

BIN = $(SRC:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -I ../libft/ -c $(SRC)

clean:
	@rm -rf $(BIN)

re: fclean all
