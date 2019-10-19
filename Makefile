# FILES
GNL		= get_next_line
NAME	= $(GNL)_bonus
UTILS	= $(GNL)_utils_bonus
SRC		= cat.c \
		  killer.c \
		  multiple.c
BIN		= $(SRC:%.c=%.out)
SRC		= $(addprefix src/, $(SRC))

# COMPILATION
BZISE	?= 32
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=$(BSIZE)

all: $(BIN)

clean:
	rm -rf *.out

fclean: clean

re: fclean all

%.out: %.c $(NAME).c $(UTILS).c $(NAME).h
	$(CC) $(CFLAGS) $(NAME).c $(UTILS).c $< -o $@

.PHONY: clean fclean re
