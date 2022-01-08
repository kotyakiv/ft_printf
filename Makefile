SRC = ft_printf.c print_conversion.c conversion_specification.c to_base.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
CFLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ) libft.a

	@gcc -o a main.c libftprintf.a libft.a
	@rm -f $(OBJ)
clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
