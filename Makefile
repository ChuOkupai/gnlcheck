# FILES
GNL		= get_next_line
NAME	= $(GNL)_bonus
UTILS	= $(GNL)_utils_bonus
SRC		= cat.c \
		  killer.c \
		  multiple.c
BIN		= $(SRC:%.c=%)

# COMPILATION
CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror -D BUFFER_SIZE=32 -I.

all: $(BIN)

clean:
	rm -rf $(BIN)

fclean: clean

re: fclean all

%: src/%.c $(NAME).c $(UTILS).c $(NAME).h
	$(CC) $(CFLAGS) $(NAME).c $(UTILS).c $< -o $@

.PHONY: clean fclean re
