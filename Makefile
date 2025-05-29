# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 13:29:12 by dlesieur          #+#    #+#              #
#    Updated: 2025/05/29 15:28:09 by dlesieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Importation of preconfiguration from personal library
include libft/build/colors.mk

# Variables
NAME = push_swap.a
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR=./src
DIR_UTILS=$(SRC_DIR)/utils/
DIR_CHECKER=$(SRC_DIR)/checker/
DIR_OPERATIONS=$(SRC_DIR)/operations/
DIR_TEST=$(SRC_DIR)/micro_test/
DIR_ALGORITHM=$(SRC_DIR)/algorithms
AR= ar -rcs
PROGRAM_TEST=op_test
PROGRAMS=$(PROGRAM_TEST)
MAKEFLAGS += --no-print-directory

# Separate library sources from test sources
LIB_SRCS = $(DIR_OPERATIONS)/push.c $(DIR_OPERATIONS)/rotate.c $(DIR_OPERATIONS)/rrotate.c $(DIR_OPERATIONS)/swap.c \
		   $(DIR_UTILS)/utils.c
LIB_OBJECTS = $(LIB_SRCS:.c=.o)

# build all the project
all: build $(PROGRAM_TEST)

# Build all the libraries once and for all
build: build-libft $(NAME)

# Compile source files to object files
%.o : %.c
	@$(CC) $(CFLAGS) -I./inc -c $< -o $@
    
#Build libft dependency
build-libft:
	@$(MAKE) -C libft

# Use LIB_OBJECTS instead of OBJECTS
$(NAME): $(LIB_OBJECTS)
	@echo "$(BLUE)[ARCHIVE]Creating push_swap.a$(RESET)"
	@$(AR) $(NAME) $(LIB_OBJECTS)
	@echo "$(MAGENTA)[DONE] Library push_swwap.a successfully created$(RESET)"


# Add $(NAME) dependency and use correct library name
$(PROGRAM_TEST): build-libft $(NAME)
	@echo "Compiling operation test..."
	@$(CC) $(CFLAGS) -I./inc -I./libft $(DIR_TEST)/operation_test.c -L. -l:push_swap.a -L./libft -lft -o op_test
	@echo "Compilation complete."

run: op_test
	@echo "Running test..."
	./$(PROGRAM_TEST)

# Clean objects
clean:
	$(RM) $(LIB_OBJECTS)

# Clean all the Programs and objects    
fclean: clean
	$(RM) $(NAME) $(PROGRAMS)
	@$(MAKE) fclean -C libft

# Reset the whole implementation
re: fclean all
	clear

.PHONY: run-micro_test clean fclean build-libft build