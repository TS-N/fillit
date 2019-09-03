NAME = fillit.a

SRC = fillit.c parseTet.c
OBJ = fillit.o parseTet.o
HEADER = fillit.h
MAIN = main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCH = libft/libft.a

.PHONY: all clean fclean re debug test mlibft mfillit

all: $(NAME)

$(NAME): $(SRC)
	make mlibft
	make mfillit

mfillit:
	$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o fillit -I $(HEADER) $(ARCH)

mlibft:
	make -C libft/

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all

debug:
	$(CC) -g $(CFLAGS) $(MAIN) $(OBJ) -o fillit -I $(HEADER) $(ARCH)

test :
	make mfillit
	make run  -C test/
