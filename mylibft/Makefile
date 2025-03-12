# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 13:36:21 by poverbec          #+#    #+#              #
#    Updated: 2025/03/05 14:02:38 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# --------------------MAIN-------------------- #

NAME = libft.a
CC = cc
AR = ar
INCLUDE_DIR = ./include
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDE_DIR)

# --------------------SOURCES ---------------- #
VPATH = ./libft ./printf ./gnl
MY_SOURCES_libft = ft_atoi.c	\
			ft_atol.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_substr.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strmapi.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c 

MY_SOURCES_libft_lst= ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

MY_SOURCES_PF = ft_printf_func.c \
			ft_printf_func2.c \
			ft_printf.c

MY_SOURCES_GNL = get_next_line.c \
				get_next_line_utils.c

# -------------------- OBJECTS ---------------- #
OBJECT_DIR = objects
SOURCES = $(MY_SOURCES_libft) $(MY_SOURCES_libft_lst) $(MY_SOURCES_PF) $(MY_SOURCES_GNL)
OBJECTS = $(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# -------------------- Colors ---------------- #
Color_Off = \033[0m
BGreen = \033[1;32m 
Red = \033[0;31m

$(OBJECT_DIR)/%.o: %.c | $(OBJECT_DIR)
	@echo "$(BGreen) Compiling $< to $@ $(Color_Off)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR):
	@echo "$(BGreen) Creating $(OBJECT_DIR) directory $(Color_Off)"
	@mkdir -p $(OBJECT_DIR)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(BGreen) \n Storing object file $(NAME) $(Color_Off)"
	$(AR) -rcs $(NAME) $(OBJECTS)
	@echo "$(BGreen) \n Compiling finished $(Color_Off)"



clean:
	@echo "$(Red) Cleaning Object Files $(Color_Off)"
	rm -rf $(OBJECT_DIR)

fclean: clean
	@echo "$(Red)Removing $(NAME)$(Color_Off)"
	rm -f $(NAME)

re: fclean all 

.PHONY: re clean fclean all