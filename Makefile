# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 15:03:32 by gumendes          #+#    #+#              #
#    Updated: 2025/02/04 17:12:20 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
RM			=	rm -f
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

SRC			=	$(SRC_PATH)/main.c $(SRC_PATH)/parse.c

OBJ			=	$(SRC:.c=.o)

# Targets
all: $(LIBFT) $(PRINTF) $(NAME)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Build the printf library
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

# Build the fractol program
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(PRINTF)

# Clean object files
clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

# Full clean
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re