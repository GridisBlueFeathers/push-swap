# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 14:23:33 by svereten          #+#    #+#              #
#    Updated: 2024/05/29 13:03:05 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap 

BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_PROJ = push_swap \
		   utils/arg \
		   utils/print_error \
		   stack/stack_init \
		   stack/stack_append \
		   stack/swap \
		   stack/push \
		   stack/rotate \
		   stack/print_stack_op \
		   stack/stack_utils \
		   stack/stack_find \
		   algo/algo \
		   algo/algo_calc_dir \
		   algo/algo_move_dir \
		   algo/algo_cases \

BONUS_PROJ = checker_bonus \
			 stack/stack_init_bonus \
			 stack/stack_utils_bonus \
			 stack/stack_append_bonus \
			 stack/stack_find_bonus \
			 stack/push_bonus \
			 stack/swap_bonus \
			 stack/rotate_bonus \
			 stack/print_stack_op_bonus \
			 utils/print_error_bonus \
			 utils/arg_bonus \

SRC_DIR = src
OBJ_DIR = obj
BONUS_DIR = bonus
LIBFT_DIR = libft

SRCS = $(SRC_PROJ:%=${SRC_DIR}/%.c)
OBJS = $(SRC_PROJ:%=${OBJ_DIR}/%.o)

BONUSES= $(BONUS_PROJ:%=${BONUS_DIR}/%.c)
BONUS_OBJS = $(BONUS_PROJ:%=${OBJ_DIR}/%.o)

OBJ_DIRS = $(sort $(dir ${OBJS}))

INCLUDE = -I./include -I./libft/include

LIBFT = ./libft/libft.a

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c | ${OBJ_DIRS}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	
bonus: ${BONUS_NAME}

${BONUS_NAME}: ${BONUS_OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${INCLUDE} $^ -o $@

${OBJ_DIR}/%.o: ${BONUS_DIR}/%.c | ${OBJ_DIRS}
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
	rm -rf ${BONUS_NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
