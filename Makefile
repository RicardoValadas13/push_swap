NAME = push_swap

SRCS =	./srcs/helpers.c \
		./srcs/listmanage.c \
		./srcs/main.c \
		./srcs/moves.c \
		./srcs/moveshelper.c \
		./srcs/sort.c	\
		./srcs/sort_utils.c

PRINTF_DIR = ./srcs/ft_printf/
LIBFT_DIR = ./srcs/libft/
PRINTF = $(PRINTF_DIR)/ft_printf.a
LIBFT = $(LIBFT_DIR)/libft.a


OBJS :=$(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS) 
	@$(CC) $(OBJS) $(CFLAGS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft -o $(NAME)  

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
	@$(MAKE) -C ./srcs/ft_printf --no-print-directory --silent

$(LIBFT):
	@$(MAKE) -C ./srcs/libft --no-print-directory --silent

tester: $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS)

clean_library:
	@$(MAKE) -C ./srcs/ft_printf fclean --no-print-directory --silent
	@$(MAKE) -C ./srcs/libft fclean --no-print-directory --silent

clean:
	@rm -f $(OBJS)

fclean: clean clean_library
	@rm -f $(NAME)
	@rm -f checker

re: fclean all

.PHONY: all tester bonus clean fclean runner re
