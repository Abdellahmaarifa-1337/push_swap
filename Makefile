CC = CC


ALGORITHMS_SRC = /src/algorithms/calc_moves.c src/algorithms/sort_100.c \
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
				src/helpers/str_isdigit.c src/helpers/swap_top.c \

OPERATIONS_SRC = src/operations/main.c src/operations/pa.c \
				src/operations/pb.c src/operations/ra.c \
				src/operations/rb.c src/operations/rr.c \
				src/operations/rra.c src/operations/rrb.c \
				src/operations/rrr.c src/operations/sa.c \
				src/operations/sb.c src/operations/ss.c \

PUSH_SWAP_SRC = src/push_swap.c src/sort_stack.c src/error_checker.c

CHECKER = src/checker.c src/error_checker.c


SRC = ${ALGORITHMS_SRC} ${HELPERS_SRC} ${OPERATIONS_SRC} ${OPERATIONS_SRC} ${PUSH_SWAP_SRC}
CHECKER_SRC = ${ALGORITHMS_SRC} ${HELPERS_SRC} ${OPERATIONS_SRC} ${OPERATIONS_SRC} ${CHECKER}

OBJ = ${SRC:.c=.o}
CHECKER_OBJ = ${CHECKER_SRC:.c=.o}
NAME = push_swap.out
CHECKER = checker.out

all: ${ALGORITHMS_OBJ} ${HELPERS_OBJ} ${OPERATIONS_OBJ} ${OPERATIONS_OBJ} ${PUSH_SWAP}
	${CC} ${CFLAGS}  ${ALGORITHMS_OBJ} ${HELPERS_OBJ} ${OPERATIONS_OBJ} ${OPERATIONS_OBJ} ${PUSH_SWAP} -o ${NAME}

checker: ${CHECKER_OBJ}
	${CC} ${CHECKER_OBJ} -o ${CHECKER}

${OBJ}: ${SRC}



${CHECKER_OBJ}: ${CHECKER_SRC}
${ALGORITHMS_SRC} ${HELPERS_SRC} ${OPERATIONS_SRC} ${OPERATIONS_SRC} ${PUSH_SWAP_SRC}
clean:
	rm -rf ${OBJ} ${CHECKER_OBJ}

