# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 09:43:19 by gumendes          #+#    #+#              #
#    Updated: 2025/01/21 17:01:14 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g

# Library Paths
LIBFT_PATH		=	libft

# Libraries
LIBFT			=	$(LIBFT_PATH)/libft.a

# Includes
INCLUDES = -I$(LIBFT_PATH)

# Output Name
NAME = libftprintf.a

# Source Files
SRC = ft_printf.c ft_printlowhexa.c ft_printnbr.c ft_printptr.c \
	  ft_printstr.c ft_printuphexa.c ft_printutils.c ft_printunbr.c

# Object Files
OBJ = $(SRC:.c=.o)

# Libft Object Files
LIBFT_OBJ = $(LIBFT_PATH)/ft_calloc.o $(LIBFT_PATH)/ft_putchar_fd.o \
			$(LIBFT_PATH)/ft_putstr_fd.o $(LIBFT_PATH)/ft_strlen.o \
			$(LIBFT_PATH)/ft_bzero.o

# Build Target
all: $(LIBFT) $(NAME)

# Build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Build the printf library
$(NAME): $(OBJ) $(LIBFT_OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
