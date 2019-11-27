NAME = fillit

SRC = fillit.c parsetet.c ft_flstaddend.c ft_flstnew.c  ft_flstdel.c ft_flstreset.c grid.c print.c
OBJ = fillit.o parsetet.o ft_flstaddend.o ft_flstnew.o ft_flstdel.o ft_flstreset.o grid.o print.o
HEADER = ./include
MAIN = main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCH = libft/libft.a

.PHONY: all clean fclean re debug test mlibft mfillit fillit

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
	/bin/rm -f fillit
	make fclean -C libft/

re: fclean all

debug:
	$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	$(CC) -g $(CFLAGS) $(MAIN) $(OBJ) -o fillit -I $(HEADER) $(ARCH)

test:
	make mfillit
	make run  -C test/
