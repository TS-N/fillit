NAME = fillit.a

SRC = fillit.c
OBJ = fillit.o
HEADER = fillit.h
MAIN = main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCH = libft/libft.a

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER) -o $(OBJ)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o fillit -I $(HEADER) $(ARCH)

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re : fclean all
