gcc -Wall -Wextra -Werror -c *.c
ar rc libft.a *.o
find . -type f -name "*.o" -delete
