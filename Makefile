# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/17 18:24:11 by crenault          #+#    #+#              #
#    Updated: 2015/02/24 12:46:29 by rbenjami         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include			libft/Makefile.sources
include			Makefile.classic_sources
include			Makefile.boosted_sources
include			Makefile.tests_sources

export	CC		=	clang

NAME			=	mlx_helpers

CFLAGS			=	-Wall -Wextra -Werror -O3 -g -pedantic

INC				+=	-I/usr/X11/include

LIB				=	-L./libft -lft -L/usr/X11/lib -lmlx -lXext -lX11 -lm

TMP				=	$(addprefix libft/, $(LIB_SRC))
OBJ_LIBFT		=	$(TMP:.c=.o)

HEAD_LIBFT		=	libft/includes/libft.h

all:
	@echo "\033[31musage: make [classic, boosted]"

# ********************************** TESTS *********************************** #

TESTS_SRC_DIR	=	tests

TESTS_FILES		+=	main.c

TESTS_SRC		=	$(addprefix $(TESTS_SRC_DIR)/, $(TESTS_FILES))

TESTS_OBJ		=	$(TESTS_SRC:.c=.o)

classic_test:	lib$(NAME)_classic.a $(TESTS_OBJ)
	@$(CC) $(CFLAGS) -o classic_test $(TESTS_OBJ) $(LIB) -L./ -l$(NAME)_classic
	@printf '\033[33mCompilation of classic_test: \033[32mSuccess \t\t\
			\033[34m[\033[32m✔\033[34m]\033[0m\n'

# boosted_test:


# ********************************* CLASSIC ********************************** #

CLASSIC_SRC_DIR	=	classic

CLASSIC_FILES	+=

CLASSIC_SRC		=	$(addprefix $(CLASSIC_SRC_DIR)/, $(CLASSIC_FILES))

CLASSIC_OBJ		=	$(CLASSIC_SRC:.c=.o)

lib$(NAME)_classic.a: libft/libft.a $(CLASSIC_OBJ)
	@ar -rc lib$(NAME)_classic.a $(CLASSIC_OBJ)
	@ranlib lib$(NAME)_classic.a
	@echo ""
	@printf '\033[33mCompilation of mlx_helpers_classic: \033[32mSuccess \t\
			\033[34m[\033[32m✔\033[34m]\033[0m\n'

classic:		lib$(NAME)_classic.a

# ********************************* BOOSTED ********************************** #

BOOSTED_SRC_DIR	=	boosted

BOOSTED_FILES	+=

BOOSTED_SRC		=	$(addprefix $(BOOSTED_SRC_DIR)/, $(BOOSTED_FILES))

BOOSTED_OBJ		=	$(BOOSTED_SRC:.c=.o)

lib$(NAME)_boosted.a: libft/libft.a $(BOOSTED_OBJ)
	@ar -rc lib$(NAME)_boosted.a $(BOOSTED_OBJ)
	@ranlib lib$(NAME)_boosted.a
	@echo ""
	@printf '\033[33mCompilation of mlx_helpers_boosted: \033[32mSuccess \t\
			\033[34m[\033[32m✔\033[34m]\033[0m\n'

boosted:		lib$(NAME)_boosted.a

# *********************************** ALL ************************************ #

libft/libft.a:	$(TMP)
	@make -C libft

%.o:			%.c
	@echo -n _
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(CLASSIC_OBJ)
	@rm -f $(BOOSTED_OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@rm -f lib$(NAME)_classic.a
	@rm -f lib$(NAME)_boosted.a
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean classic boosted re
