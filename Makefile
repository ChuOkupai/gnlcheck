# FILES
GNL		= get_next_line
NAME	= $(GNL)_bonus
UTILS	= $(GNL)_utils_bonus
SRC		= cat.c \
		  killer.c \
		  multiple.c
BIN		= $(SRC:%.c=%.out)

# COMPILATION
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=32 -I.

all: $(BIN)

clean:
	rm -rf *.out

fclean: clean

re: fclean all

%.out: src/%.c $(NAME).c $(UTILS).c $(NAME).h
	$(CC) $(CFLAGS) $(NAME).c $(UTILS).c $< -o $@

.PHONY: clean fclean re
