NAME = rush02
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : main.o
	$(CC) $(CFLAGS) -o rush02 main.o

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

clean :
	rm -f main.o

fclean : clean
	rm -f rush02

re : fclean all
