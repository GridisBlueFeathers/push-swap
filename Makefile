# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
#    Updated: 2024/05/23 16:44:00 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap 

CC = cc

CFLAGS = -Wall -Wextra -Werror  

SRC_PROJ = main \
		   utils/arg \
		   stack/stack_init \
		   stack/stack_append \
		   stack/swap \
		   stack/push \
		   stack/rotate \
		   stack/print_stack_op \
		   stack/stack_utils \
		   algo/algo \

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft

SRCS = $(SRC_PROJ:%=${SRC_DIR}/%.c)
OBJS = $(SRC_PROJ:%=${OBJ_DIR}/%.o)

OBJ_DIRS = $(sort $(dir ${OBJS}))

INCLUDE = -I./include -I./libft/include

LIBFT = ./libft/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT}:
	${MAKE} -C ${LIBFT_DIR}

${OBJ_DIRS}:
	mkdir -p $@

clean:
	rm -rf ${OBJ_DIR}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	rm -rf ${NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
