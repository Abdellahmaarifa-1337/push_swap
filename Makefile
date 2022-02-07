CC = cc
CFLAGS = -Wall -Werror -Wextra

ALGORITHMS_SRC = src/algorithms/calc_moves.c src/algorithms/sort_big.c \
				src/algorithms/sort_five.c src/algorithms/sort_three.c 

HELPERS_SRC = src/helpers/absolute.c src/helpers/append.c \
				src/helpers/copy_sorted_stack.c src/helpers/copy_stack.c \
				src/helpers/find_lis.c src/helpers/find_max.c \
				src/helpers/find_min.c src/helpers/ft_atoi.c \
				src/helpers/ft_isdigit.c src/helpers/ft_putstr.c \
				src/helpers/ft_strncmp.c src/helpers/get_next_line.c \
				src/helpers/get_next_line_utils.c src/helpers/init_stack.c \
				src/helpers/is_in_lis.c src/helpers/is_sorted.c \
				src/helpers/push_top.c src/helpers/rotate_diff.c \
				src/helpers/rotate_rr.c src/helpers/rotate_rrr.c \
				src/helpers/rotate_stack.c src/helpers/rotate_stack_reverse.c \
				src/helpers/shift.c src/helpers/sort_arr.c \
				src/helpers/str_isdigit.c src/helpers/swap_top.c 

OPERATIONS_SRC = src/operations/main.c src/operations/pa.c \
				src/operations/pb.c src/operations/ra.c \
				src/operations/rb.c src/operations/rr.c \
				src/operations/rra.c src/operations/rrb.c \
				src/operations/rrr.c src/operations/sa.c \
				src/operations/sb.c src/operations/ss.c 

PUSH_SWAP_MAIN = src/push_swap.c src/sort_stack.c src/error_checker.c

CHECKER_MAIN = src/checker.c src/error_checker.c


PUSH_SWAP_SRC = ${PUSH_SWAP_MAIN} ${OPERATIONS_SRC} ${HELPERS_SRC} ${ALGORITHMS_SRC}
CHECKER_SRC = ${CHECKER_MAIN} ${OPERATIONS_SRC} ${HELPERS_SRC} ${ALGORITHMS_SRC}

PUSH_SWAP_OBJ = ${PUSH_SWAP_SRC:.c=.o}
CHECKER_OBJ = ${CHECKER_SRC:.c=.o}


NAME = push_swap
CHECKER = checker

.c.o: 
	${CC} ${CFLAGS} -c $< -o $@

all:  ${NAME}

${NAME}: ${PUSH_SWAP_OBJ}
	${CC} ${CFLAGS} ${PUSH_SWAP_OBJ} -o ${NAME}


checker: ${CHECKER_OBJ}
	${CC} ${CFLAGS} ${CHECKER_OBJ} -o ${CHECKER}

${PUSH_SWAP_OBJ}: ${PUSH_SWAP_SRC}
${CHECKER_OBJ}: ${CHECKER_SRC}


clean:
	rm -rf ${PUSH_SWAP_OBJ} ${CHECKER_OBJ}
fclean: clean
	rm -rf  ${NAME} ${CHECKER}
re: fclean all

.PHONY: clean fclean re
