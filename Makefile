NAME = push_swap.a

CFLAGS = -Wall -Werror -Wextra

SRC = main.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJ_BONUS)
	ar -crs $(NAME) $(OBJ_BONUS)

$(NAME) : $(OBJ)
	ar -crs $@ $^

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus