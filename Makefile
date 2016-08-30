# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oexall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/28 12:11:33 by oexall            #+#    #+#              #
#    Updated: 2016/08/30 08:53:30 by oexall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=42sh

CC= gcc
CFLAGS= -Wall -Werror -Wextra
LIBS= -ltermcap -L libft/ -lft
HEADER= -I include/ -I libft

all: $(NAME)

SRC_PATH= srcs/
SRC1= main.c ft_loop.c ft_errors.c \
	  ft_read_environ.c ft_getenv.c ft_setenv.c ft_update_env.c \
	  ft_dupenviron.c \
	  ft_termcap.c

SRCS= $(addprefix $(SRC_PATH), $(SRC1))

$(NAME):
	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(LIBS) $(HEADER)

clean:
	@rm $(NAME)

fclean: clean
	@#@make -C libft re

re: fclean all

