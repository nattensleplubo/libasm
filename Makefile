NAME = libasm.a

EXE_NAME = libasm_test

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s	\

FLAGS = -Wall -Werror

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:%.s=%.o}

LIBASM_PATH = -L. -lasm

all: ${NAME} ${EXE_NAME}

%.o: %.s
	nasm -f elf64 $(FLAGS) -o $@ $<

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

${EXE_NAME} : maintest.c ${NAME}
	gcc ${CFLAGS} -o ${EXE_NAME} maintest.c ${LIBASM_PATH}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re