# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 13:29:12 by dlesieur          #+#    #+#              #
#    Updated: 2025/05/28 17:52:35 by dlesieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
RM = rm -rf
CC = cc
FLAGS = -Wall -Wextra -Werror
CFLAGS = $(FLAGS)
DIR_MICRO=./src/micro_test
SRCS = $(DIR_MICRO)/operation_test.c
MICRO_TEST = 
hello:
	touch hello
	@echo "hello, world"
	@echo "this line will print if the file hello does not exist."

made:
	${CC} $(FLAGS) make.c -o make

build-libft:
	@$(MAKE) -C libft

run-micro_test: build-libft
	$(CC) $(FLAGS) -I./inc -I./libft src/operations/push.c src/micro_test/operation_test.c -L./libft -lft -o op_test

clean: hello
	${RM} hello a.out make