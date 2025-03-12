


NAME 	= philo
CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g -I inc/
LIBFT	= ./mylibft/libft.a


OBJ_DIR = obj/
BIN_DIR = bin/
SOURCE_DIR = src/


# ---------- Subjects ---------- #
MY_SOURCES = \ 
		$(SOURCE_DIR)main.c \


# ---------- Objects ---------- #

MY_OBJECTS=$(MY_SOURCES:$(SOURCE_DIR)%.c=$(OBJ_DIR)%.o)


# ---------- COLORS AND STUFF ---------- #
Color_Off = \033[0m
BIYellow = \033[1;93m
Yellow = \033[0;33m
BGreen = \033[1;32m 
On_Yellow = \033[43m
On_Green = \033[42m
Red = \033[0;31m


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SOURCE_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


$(NAME):  $(MY_OBJECTS) $(LIBFT)
	@echo "$(BIYellow) Compiling $(NAME) $(Color_Off)"
	@$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME) $(MLX)
	@if [ -f $(NAME) ]; then \
		echo "$(On_Yellow)------------------------------------------$(Color_Off)"; \
		echo "$(BGreen)PROCESS COMPLETED SUCCESSFULLY!$(Color_Off)"; \
		echo "$(On_Green)------------------------------------------$(Color_Off)"; \
	else \
		echo "$(Red)failed to compile $(NAME) $(Color_Off)"; \
		exit 1; \
	fi

$(LIBFT):
	make -C ./libft


test: CFLAGS = -g
test: $(NAME)

 ------------Debug for leaks---------------
# CFLAGS	= -Wall -Wextra -Werror -g -I inc/ -fsanitize=address
debug: -Wall -Wextra -Werror -g -I inc/ -fsanitize=address


clean:
	@echo "$(Yellow)-----Removing Object Files--------$(Color_Off)"
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	make -C libft fclean

fclean: clean
	@echo "$(On_Yellow)Removing Executables...$(Color_Off)"
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR) $(BIN_DIR)
	make -C libft fclean

re: fclean all

#norm:
#	@cd src && norminette | grep "Error:" | wc -l
#norminette: norm

# f: fclean
# f: CFLAGS += -g -fsanitize=address
f: fclean
	$(CFLAGS) += -g -fsanitize=address
	make all
.PHONY: re clean fclean all