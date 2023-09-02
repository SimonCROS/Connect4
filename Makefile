# Properties

NAME				:= connect4

override SRCS		:=					\
		src/main.c						\
		src/utils.c						\

all:
	cc $(SRCS) -Wall -Wextra -Werror -Iincludes -o connect4

debug:
	cc $(SRCS) -Wall -Wextra -Iincludes -fsanitize=address -g3 -o connect4

.PHONY: all
