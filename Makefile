


NAME 		= philo
MAX_THRDS	= 200
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I inc/
# LDFLAGS = -lpthread


OBJ_DIR = obj/
SOURCE_DIR = ./src
INC_DIR = inc

vpath %.c $(SOURCE_DIR)
vpath %.h $(INC_DIR)



# ---------- Subjects ---------- #
MY_SOURCES = \
		main.c \
		test.c

HEADERS = philo.h

# ---------- Objects ---------- #

OBJ 	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# MY_OBJECTS=$(MY_SOURCES:$(SOURCE_DIR)%.c=$(OBJ_DIR)%.o)


# ---------- COLORS AND STUFF ---------- #
Color_Off = \033[0m
BLUE	=	\033[0;34m
BIYellow = \033[1;93m
Yellow = \033[0;33m
BGreen = \033[1;32m 
On_Yellow = \033[43m
On_Green = \033[42m
Red = \033[0;31m


all: $(NAME)

start_compile:
	@printf "$(BLUE)Compiling Philosophers...$(Color_Off)\n"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)
	@printf "$(BGreen)SUCCESS - $(NAME) has been successfully compiled$(NO_COLOR)\n"
	@printf "$(BGreen)Compiling Files: Done$(Color_Off)\n"


$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(BGreen)Compiled $(notdir $<)$(Color_Off)\n"


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)



test: CFLAGS = -g
test: $(NAME)

#------------Debug for leaks---------------
# CFLAGS	= -Wall -Wextra -Werror -g -I inc/ -fsanitize=address
debug: -Wall -Wextra -Werror -g -I inc/ -fsanitize=address


clean:
	@echo "$(Yellow)-----Removing Object Files--------$(Color_Off)"
	@rm -rf $(OBJ_DIR) && printf "$(Yellow)Removing philosophers object files...$(Color_Off)\n"


fclean: clean
	@echo "$(On_Yellow)Removing Executables...$(Color_Off)"
	@rm -f $(NAME) && printf "$(Yellow)Removing philosophers binary$(Color_Off)\n"
	@rm -rf $(OBJ_DIR) 
	@printf "$(On_Green)Cleaned up $(NAME)$(Color_Off)\n"


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