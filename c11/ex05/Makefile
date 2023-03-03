NAME = do-op
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : calculate.o ft_atoi.o do_op.o ft_putnbr.o
	$(CC) $(CFLAGS) -o $(NAME) calculate.o ft_atoi.o do_op.o ft_putnbr.o

.c.o : 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f calculate.o ft_atoi.o do_op.o ft_putnbr.o

fclean : clean
	rm -f do-op

re : fclean all

.PHONY: all clean fclean re