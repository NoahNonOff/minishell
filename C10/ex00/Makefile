SRCS = ft.c main.c
EXEC = ft_display_file
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
