# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 13:32:16 by poverbec          #+#    #+#              #
#    Updated: 2025/04/07 16:36:31 by poverbec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo
MAX_THRDS	= 200
CC			= cc
#---------linux---------
CFLAGS	= -Wall -Wextra -Werror -g -I inc/ -ldl -lglfw -pthread -lm
#----------mac ---------
CFLAGS		= -Wall -Wextra -Werror -g -I inc/
# LDFLAGS = -lpthread


SOURCE_DIR = ./src
SIMULATION_DIR = ./src/simulation
INITALISE_DIR = ./src/initialise_structs
INC_DIR = inc
OBJ_DIR = obj

VPATH = $(SOURCE_DIR):$(SIMULATION_DIR):$(INITALISE_DIR):$(INC_DIR)


# ---------- Subjects ---------- #
MY_SOURCES = \
		main.c \
		check_arg.c \
		helper.c \
		init.c \
		destroy_mutex.c \
		create_threads.c \
		eats_sleeps_thinks.c \
		check_philo_alive.c \
		philo_eats_helper.c \
		print.c \
		get_times.c \
		wait_for_threads.c \
		testing.c

HEADERS = philo.h

# ---------- Objects ---------- #

OBJ 	= $(addprefix $(OBJ_DIR)/, $(MY_SOURCES:.c=.o))
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


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)



test: CFLAGS = -g
test: $(NAME)

#------------Debug for leaks---------------
# CFLAGS	= -Wall -Wextra -Werror -g -I inc/ -fsanitize=address
debug: -Wall -Wextra -Werror -g -I inc/ -fsanitize=address


valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./philo 4 310 200 100 2


helgrind:
	valgrind --tool=helgrind -s ./philo 2 200 200 70 

assembly:
	$(CC) -S src/main.c

clean:
	@echo "$(Yellow)-----Removing Object Files--------$(Color_Off)"
	@rm -rf $(OBJ_DIR) && printf "$(Yellow)Removing philosophers object files...$(Color_Off)\n"


fclean: clean
	@echo "$(On_Yellow)Removing Executables...$(Color_Off)"
	@rm -f $(NAME) && printf "$(Yellow)Removing philosophers binary$(Color_Off)\n"
	@rm -rf $(OBJ_DIR) 
	@printf "$(On_Green)Cleaned up $(NAME)$(Color_Off)\n"


re: fclean
	$(MAKE) all

norm:
	@cd src && norminette | grep "Error:" | wc -l
norminette: norm

# f: fclean
# f: CFLAGS += -g -fsanitize=address
f: fclean
	$(CFLAGS) += -g -fsanitize=address
	make all

.PHONY: re clean fclean all