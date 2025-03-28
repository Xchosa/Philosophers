# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 13:32:16 by poverbec          #+#    #+#              #
#    Updated: 2025/03/25 15:59:54 by poverbec         ###   ########.fr        #
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
INC_DIR = inc
OBJ_DIR = obj

VPATH = $(SOURCE_DIR):$(SIMULATION_DIR):$(INC_DIR)


# ---------- Subjects ---------- #
MY_SOURCES = \
		main.c \
		check_arg.c \
		helper.c \
		init.c \
		destroy_mutex.c \
		routine.c \
		simulation.c \
		check_philo_live.c \
		philo_eats.c \
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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./philo 5 200 100 150 5


helgrind:
	valgrind --tool=helgrind ./philo 2 200 200 7 

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

#norm:
#	@cd src && norminette | grep "Error:" | wc -l
#norminette: norm

# f: fclean
# f: CFLAGS += -g -fsanitize=address
f: fclean
	$(CFLAGS) += -g -fsanitize=address
	make all

.PHONY: re clean fclean all