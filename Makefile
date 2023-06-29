NAME = push_swap

SRCS =	./srcs/helpers.c \
		./srcs/listmanage.c \
		./srcs/main.c \
		./srcs/moves.c \
		./srcs/moveshelper.c \
		./srcs/sorting.c

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -fsanitize=address $(OBJS) -o $(NAME) 

runner:
	cc -Wall -Werror -Wextra $(SRCS) -o push_swap
	@mv push_swap ./push_swap_visualizer-master/build
	@cd ./push_swap_visualizer-master/build && ./bin/visualizer

tester: $(SRCS)
	cc $(CFLAGS) $(SRCS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f checker

re: fclean all

.PHONY: all tester bonus clean fclean runner re

#COLORS                                                                         
GREEN = \033[1;32m
RED = \033[1;31m
ORANGE = \033[38;5;208m
DEFAULT = \033[0m
YELLOW = \033[1;33m