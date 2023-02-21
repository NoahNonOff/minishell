SRCS = display.c ft2.c ft.c main.c
EXEC = ft_tail
OBJS = ${SRCS:.c=.o}
CC = gcc -Wall -Wextra -Werror

all: ${EXEC}

.c.o:
	@${CC} -o $@ -c $<

${EXEC}: ${OBJS}
	@${CC} -o $@ $^

clean:
	@rm -f ${OBJS}

fclean:
	@rm -f ${EXEC}
