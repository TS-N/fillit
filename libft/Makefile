# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 16:17:19 by tsaura-n          #+#    #+#              #
#    Updated: 2019/08/21 20:41:02 by tsaura-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isprint.c ft_strcpy.c ft_strncpy.c ft_tolower.c \
	ft_isalpha.c ft_strcat.c ft_strlen.c ft_strnstr.c ft_toupper.c \
	ft_isascii.c ft_strchr.c ft_strncat.c ft_strlcat.c ft_strdup.c \
	ft_strndup.c ft_strrchr.c ft_isdigit.c ft_strcmp.c ft_strncmp.c \
	ft_strstr.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c  \
	ft_memcpy.c ft_memccpy.c ft_bzero.c ft_atoi.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
	ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strtrim_char.c ft_strsplit.c \
	ft_wcnt.c ft_wlen.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_strset.c ft_intlen.c ft_intsize.c ft_lstnew.c \
	ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstaddend.c ft_lstiter.c \
	ft_lstmap.c ft_put_ithdigit.c ft_put_ithdigit_fd.c get_next_line.c
HEADER = includes/
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	ar rc $@ *.o

clean:
	/bin/rm -f *.o
	
fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
