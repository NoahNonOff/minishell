EXEC = do-op
SRCS = ft_atoi.c ft.c ft_operateur.c main.c
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

cleanall: clean fclean
