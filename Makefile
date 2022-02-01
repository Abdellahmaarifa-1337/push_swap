CC = CC



SRC = $(wildcard src/*.c src/*/*.c)

OBJ = ${SRC:.c=.o}
NAME = push_swap.out

all: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

${OBJ}: ${SRC}

clean:
	rm -rf ${OBJ}

