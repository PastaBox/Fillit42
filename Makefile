# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fciprian <fciprian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 11:54:26 by fciprian          #+#    #+#              #
#    Updated: 2016/12/04 13:42:25 by fciprian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
FLAGS =	-Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

INCLUDES_PATH =	./includes
INCLUDES = $(INCLUDES_PATH)/fillit.h

SRCS_PATH =	./srcs
SRCS_FILES	=	$(SRCS_PATH)/main.c \
				$(SRCS_PATH)/ft_solver.c \
				$(SRCS_PATH)/ft_errors.c \
				$(SRCS_PATH)/ft_valid_map.c \
				$(SRCS_PATH)/ft_gestion.c \
				$(SRCS_PATH)/ft_map.c \
				$(SRCS_PATH)/ft_check_block.c \
				$(SRCS_PATH)/ft_resolution.c

.PHONY: clean all re fclean

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS_FILES) $(LIBFT) -I $(INCLUDES)

clean:
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all
