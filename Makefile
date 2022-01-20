SRC = ft_printf.c print_conversion.c conversion_specification.c to_base.c \
print_decimal.c print_octal.c sub_functions.c print_float.c print_flags.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a
CFLAGS = -c -Wall -Werror -Wextra
LIBFTPATH = libft/

all: $(NAME)

$(NAME):
	@make -C $(LIBFTPATH)
	@gcc $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ) libft/*.o

clean:
	@rm -f $(OBJ)

m: clean
	@gcc -o a main.c libftprintf.a
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

