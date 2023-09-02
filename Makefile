# Properties

NAME				:= connect4

all:
	cc main.c -Wall -Wextra -Werror -o connect4

noerr:
	cc main.c -Wall -Wextra -o connect4

.PHONY: all
