EXEC = chessmate
FLAGS = -Wall -Wextra -Werror
SRC = main.c check_args.c ft_putstr.c board.c ft_strlen.c enemies.c
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(EXEC)

$(EXEC) : $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(EXEC)

.PHONY: all clean fclean