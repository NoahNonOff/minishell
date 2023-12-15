DIR = ./srcs/
UTILS_DIR = $(DIR)/utils/
PARSE_DIR = $(DIR)/parsing/

SRC =	$(DIR)main.c						\
		$(DIR)running.c						\
		$(UTILS_DIR)utils1.c				\
		$(UTILS_DIR)utils2.c				\
		$(UTILS_DIR)utils3.c				\
		$(UTILS_DIR)utils4.c				\
		$(PARSE_DIR)check_parse.c			\
		$(PARSE_DIR)parsing.c				\
		$(PARSE_DIR)parsing_utils.c			\
		$(PARSE_DIR)token.c					\
		$(PARSE_DIR)token_ext.c				\
		$(PARSE_DIR)linked_list.c			\


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

leaks: $(NAME)
	valgrind --suppressions=./valgrind_ignore_leaks.txt --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --show-mismatched-frees=yes --read-var-info=yes ./minishell

$(NAME) : $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) -lreadline

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : minishell clean fclean re

.SILENT:

# echo >>ra >te >rge <wrth <<EOF arg1 >rth"w"$USER"erg"'   g' $?