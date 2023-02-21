NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
HEADERS = includes/

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I ${HEADERS}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean:
	rm -f ${NAME}

re : fclean all
