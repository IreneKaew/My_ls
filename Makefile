CC = gcc

NAME = a.out

SRC = ./src/ls_a.c		\
	  ./src/ls.c		\
	  ./src/main.c		\
	  ./src/ls_A.c		\
	  ./src/ls_d.c		\
	  ./src/folder.c	\
	  ./src/op_l.c		\
	  ./src/lst.c		\
	  ./src/ls_r.c		\
	  ./lib/*

RM = rm -f

LIB = -L ./lib/* -lmy

CFLAGS = -Wall -Wextra -Werror -std=c11

LDFLAGS = -L.

IDIR = -I ./include

.PHONY = all clean fclean re

$(NAME):$(SRC)
	$(CC) $(SRC) -o $(NAME) $(LDFLAGS) $(IDIR)

all:   $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:    fclean all
