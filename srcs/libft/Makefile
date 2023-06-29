# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 14:49:56 by rbenjami          #+#    #+#              #
#    Updated: 2023/06/28 17:23:55 by ricardovala      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_calloc.c\
	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strdup.c\

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Werror -Wextra

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

all: $(NAME)
$(NAME) : $(OBJ)
	@ar -crs $@ $^

clean:
	@rm -f $(OBJ) 

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 