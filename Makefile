NAME = push_swap

SRCS =	./srcs/helpers.c \
		./srcs/listmanage.c \
		./srcs/main.c \
		./srcs/check_arg.c \
		./srcs/moves.c \
		./srcs/moves_dbl.c \
		./srcs/moves_p.c \
		./srcs/moves_r.c \
		./srcs/moves_s.c \
		./srcs/sort.c \
		./srcs/sort_utils.c \
		./srcs/sort_act.c 

LIBFT_DIR = ./srcs/libft/
LIBFT = $(LIBFT_DIR)/libft.a


OBJS :=$(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)  

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C ./srcs/libft --no-print-directory --silent

tester: $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

clean_library:
	@$(MAKE) -C ./srcs/libft fclean --no-print-directory --silent

clean:
	@rm -f $(OBJS)

fclean: clean clean_library
	@rm -f $(NAME)
	@rm -f checker

re: fclean all

.PHONY: all tester bonus clean fclean runner re
