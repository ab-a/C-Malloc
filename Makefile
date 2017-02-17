##
## Makefile for  in /home/antoine/PSU_2015_malloc
##
## Made by antoine bayard
## Login   <antoine@epitech.net>
##
## Started on  Thu Jan 28 15:47:10 2016 antoine bayard
## Last update Sun Feb 14 22:22:06 2016 antoine bayard
##

SRC=	malloc.c \
	free.c \
	realloc.c \
	show_alloc_mem.c \
	list_utils.c \

NAME=	libmy_malloc_$(HOSTTYPE).so

OBJ=	$(SRC:.c=.o)

CC=	gcc

INCLUDE= -I.include

CFLAGS=	-Wall -Wextra -g $(INCLUDE) -shared -fPIC

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	ln -sf $(NAME) libmy_malloc.so

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf libmy_malloc.so

re: fclean all
