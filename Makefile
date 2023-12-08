DIR = ./srcs/
UTILS_DIR = $(DIR)/utils/
PARSE_DIR = $(DIR)/parsing/

SRC =	$(DIR)main.c						\
		$(DIR)running.c						\
		$(UTILS_DIR)utils1.c				\
		$(UTILS_DIR)utils2.c				\
		$(PARSE_DIR)check_parse.c	

CC = gcc
RM = rm -f
DEBUG = -g3
INCLUDE = -I ./include/
NAME = minishell
FLAG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o	:
	$(CC) $(FLAG) $(DEBUG) $(INCLUDE) -c $< -o $(<:.c=.o)

all : $(NAME)
	
$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) -lreadline

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : minishell clean fclean re

.SILENT:
