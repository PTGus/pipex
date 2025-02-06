# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 09:43:19 by gumendes          #+#    #+#              #
#    Updated: 2025/01/27 10:14:44 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                   Alias                                      #
#==============================================================================#

CC       = cc
AR       = ar rcs
RM       = rm -rf
CFLAGS   = -Wall -Wextra -Werror -g

#==============================================================================#
#                                 Files and Paths                              #
#==============================================================================#

NAME        = libft.a
SRCS        = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
              ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
              ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
              ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c ft_strlcat.c ft_toupper.c \
              ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
              ft_strdup.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c \
              ft_strtrim.c ft_substr.c ft_strlcpy.c ft_split.c
BONUS_SRCS  = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
              ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
              ft_lstmap.c

BUILD_DIR   = .build
OBJS        = $(SRCS:%.c=$(BUILD_DIR)/%.o)
BONUS_OBJS  = $(BONUS_SRCS:%.c=$(BUILD_DIR)/%.o)

#==============================================================================#
#                                    Rules                                     #
#==============================================================================#

all: $(NAME)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(NAME): $(BUILD_DIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GRN)[Libft successfully compiled]$(D)"

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BUILD_DIR) $(OBJS) $(BONUS_OBJS)
	@$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GRN)[Libft successfully compiled with bonus!]$(D)"

clean:
	@$(RM) $(BUILD_DIR)
	@echo "$(BCYA)[clean] Objects removed$(D)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BCYA)[fclean] Archive removed$(D)"

re: fclean all

.PHONY: all clean fclean re bonus

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#
# Colors
B   = $(shell tput bold)
RED = $(shell tput setaf 1)
GRN = $(shell tput setaf 2)
CYA = $(shell tput setaf 6)
D   = $(shell tput sgr0)
