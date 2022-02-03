CC = CC



SRC = $(wildcard  src/*/*.c src/push_swap.c src/sort_stack.c src/error_checker.c)
CHECKER_SRC = $(wildcard src/*/*.c src/checker.c src/error_checker.c)  

OBJ = ${SRC:.c=.o}
CHECKER_OBJ = ${CHECKER_SRC:.c=.o}
NAME = push_swap.out
CHECKER = checker.out
all: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

checker: ${CHECKER_OBJ}
	${CC} ${CHECKER_OBJ} -o ${CHECKER}

${OBJ}: ${SRC}
${CHECKER_OBJ}: ${CHECKER_SRC}

clean:
	rm -rf ${OBJ} ${CHECKER_OBJ}

