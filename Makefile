# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:03:32 by gumendes          #+#    #+#              #
#    Updated: 2025/02/12 10:54:20 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g

# Library Paths
LIBFT_PATH		=	libft
PRINTF_PATH		=	ft_printf

# Libraries
LIBFT		=	$(LIBFT_PATH)/libft.a
PRINTF		=	$(PRINTF_PATH)/libftprintf.a

# Includes
INCLUDES = -I. -I$(LIBFT_PATH) -I$(PRINTF_PATH)

NAME		=	pipex

SRC_PATH	=	srcs

SRC			=	$(SRC_PATH)/main.c $(SRC_PATH)/utils.c

OBJ			=	$(SRC:.c=.o)

# Targets
all: check $(NAME)

check:
	@if [ -d "$(LIBFT_PATH)" ]; then echo "[LIBFT FOUND]"; else git clone git@github.com:PTGus/libft.git $(LIBFT_PATH); fi
	@if [ -d "$(PRINTF_PATH)" ]; then echo "[PRINTF FOUND]"; else git clone git@github.com:PTGus/ft_printf.git $(PRINTF_PATH); fi

# Clone the libft repository
$(LIBFT_PATH):
	@if [ -d "$(LIBFT_PATH)" ]; then echo "[LIBFT FOUND]"; else git clone git@github.com:PTGus/libft.git $(LIBFT_PATH); fi

# Clone the ft_printf repository
$(PRINTF_PATH):
	@if [ -d "$(PRINTF_PATH)" ]; then echo "[PRINTF FOUND]"; else git clone git@github.com:PTGus/ft_printf.git $(PRINTF_PATH); fi

# Build the libft library
$(LIBFT): $(LIBFT_PATH)
	@$(MAKE) -C $(LIBFT_PATH)

# Build the printf library
$(PRINTF): $(PRINTF_PATH)
	@$(MAKE) -C $(PRINTF_PATH)

# Build the pipex program
$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

# Clean object files
clean:
	@$(RM) $(OBJ)
	@$(RM) $(LIBFT_PATH)/.build
	@$(RM) $(PRINTF_PATH)/.build

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)
	@$(RM) $(PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re