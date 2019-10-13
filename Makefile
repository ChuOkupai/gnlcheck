# FILES
GNL		= get_next_line
NAME	= $(GNL)_bonus
UTILS	= $(GNL)_utils

# COMPILATION
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=32

all: main.out

clean:
	rm -rf *.out

fclean: clean

re: fclean all

%.out: %.c $(NAME).c $(UTILS).c $(NAME).h
	$(CC) $(CFLAGS) $(NAME).c $(UTILS).c $< -o $@

.PHONY: clean fclean re
