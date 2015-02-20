# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/17 18:24:11 by crenault          #+#    #+#              #
#    Updated: 2015/02/20 11:57:47 by crenault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT_FOLD = libft/
LIBFT = -L$(LIBFT_FOLD) -lft
#LIBMLX = -L/usr/local/lib -lmlx -L/usr/X11/lib -lXext -lX11
LIBMLX = -L/Users/crenault/Downloads/minilibx -lmlx -L/usr/X11/lib -lXext -lX11

NAME = mlx_helpers
SRC = 	main.c \
		position/basics.c \
		color/basics.c \
		color/advanced.c \
		image/basics.c \
		line/basics.c

OBJS = $(SRC:.c=.o)
HDR = $(NAME).h

all: $(NAME)

re: fclean $(NAME)

$(NAME): $(OBJS) $(HDR)
	@make -C $(LIBFT_FOLD)
	@$(CC) $(LIBMLX) $(LIBFT) -o $@ $(OBJS) $(FLAGS)
	@echo "\0033[32m$(NAME) done !\0033[0m"

%.o: %.c
	@$(CC) -o $@ -c $< $(FLAGS)

.PHONY: clean fclean

clean:
	@make clean -C $(LIBFT_FOLD)
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_FOLD)
	@rm -rf $(NAME)
