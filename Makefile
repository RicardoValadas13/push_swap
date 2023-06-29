NAME = push_swap

SRCS =	./srcs/helpers.c \
		./srcs/listmanage.c \
		./srcs/main.c \
		./srcs/moves.c \
		./srcs/moveshelper.c \
		./srcs/sorting.c

OBJS :=$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

build_library:
	@$(MAKE) -C ./srcs/ft_printf 
	@$(MAKE) -C ./srcs/libft

all: $(NAME)

$(NAME): $(OBJS) build_library
	@cc $(CFLAGS) -I./srcs/ft_printf -L./srcs/ft_printf -I./srcs/libft -L./srcs/libft -fsanitize=address $(OBJS) -o $(NAME) -lftprintf -lft

runner:
	@cc -Wall -Werror -Wextra $(SRCS) build_library -o push_swap
	@mv push_swap ./push_swap_visualizer-master/build
	@cd ./push_swap_visualizer-master/build && ./bin/visualizer

tester: $(SRCS)
	@cc $(CFLAGS) $(SRCS)

clean_library:
	@$(MAKE) -C ./srcs/ft_printf clean
	@$(MAKE) -C ./srcs/libft clean

clean:
	@rm -f $(OBJS)

fclean: clean clean_library
	@rm -f $(NAME)
	@rm -f checker

re: fclean all

.PHONY: all tester bonus clean fclean runner re
