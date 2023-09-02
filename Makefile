# Properties

NAME				:= connect4

override SRCS	   :=					\
		src/main.c						\
		src/check_win.c					\
		src/utils.c						\
		src/ft_atoi.c					\
		src/ft_strlen.c					\
		src/ft_putstr.c					\
		src/ft_putendl.c				\
		src/ft_putchar.c				\

all:
	cc $(SRCS) -Wall -Wextra -Werror -Iincludes -o connect4

debug:
	cc $(SRCS) -Wall -Wextra -Iincludes -fsanitize=address -g3 -o connect4

.PHONY: all
