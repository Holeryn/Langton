SRC_FILES = Langton_ant.c include/gfx.c
CC_FLAGS = -std=c99 -Wall -g -Wextra -lX11 -Wno-unused-variable
CC = gcc

all:
	${CC} ${SRC_FILES} ${CC_FLAGS} -o Langton_ant.o

clean:
	rm -rf *~ *.o *.out
