# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:54:21 by ykot              #+#    #+#              #
#    Updated: 2022/03/13 15:17:44 by ykot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 		ft_printf.c \
			print_conversion.c \
			conversion_specification.c \
			to_base.c \
			print_decimal.c \
			sub_functions.c \
			print_flags.c \
			print_unsigned.c \
			checking.c \
			reading_option.c \
			width_precision.c \
			print_scp.c \
			print_float.c \
			print_float2.c \
			print_float3.c \
			rounding.c

OBJ = $(SRC:.c=.o)

OBJ_libft = $(LIBFTPATH)/ft_atoi.o \
			$(LIBFTPATH)/ft_lstdelone.o \
			$(LIBFTPATH)/ft_memset.o \
			$(LIBFTPATH)/ft_strchr.o \
			$(LIBFTPATH)/ft_strlcat.o \
			$(LIBFTPATH)/ft_strrchr.o \
			$(LIBFTPATH)/ft_bzero.o \
			$(LIBFTPATH)/ft_lstiter.o \
			$(LIBFTPATH)/ft_putchar.o \
			$(LIBFTPATH)/ft_strclr.o \
			$(LIBFTPATH)/ft_strlen.o \
			$(LIBFTPATH)/ft_strsplit.o \
			$(LIBFTPATH)/ft_isalnum.o \
			$(LIBFTPATH)/ft_lstnew.o \
			$(LIBFTPATH)/ft_putchar_fd.o \
			$(LIBFTPATH)/ft_strcmp.o \
			$(LIBFTPATH)/ft_strmap.o \
			$(LIBFTPATH)/ft_strstr.o \
			$(LIBFTPATH)/ft_isalpha.o \
			$(LIBFTPATH)/ft_memalloc.o \
			$(LIBFTPATH)/ft_putendl.o \
			$(LIBFTPATH)/ft_strcpy.o \
			$(LIBFTPATH)/ft_strmapi.o \
			$(LIBFTPATH)/ft_strsub.o \
			$(LIBFTPATH)/ft_isascii.o \
			$(LIBFTPATH)/ft_memccpy.o \
			$(LIBFTPATH)/ft_putendl_fd.o \
			$(LIBFTPATH)/ft_strdel.o \
			$(LIBFTPATH)/ft_strncat.o \
			$(LIBFTPATH)/ft_strtrim.c \
			$(LIBFTPATH)/ft_isdigit.o \
			$(LIBFTPATH)/ft_memchr.o \
			$(LIBFTPATH)/ft_putnbr.o \
			$(LIBFTPATH)/ft_strdup.o \
			$(LIBFTPATH)/ft_strncmp.o \
			$(LIBFTPATH)/ft_tolower.o \
			$(LIBFTPATH)/ft_isprint.o \
			$(LIBFTPATH)/ft_memcmp.o \
			$(LIBFTPATH)/ft_putnbr_fd.o \
			$(LIBFTPATH)/ft_strequ.o \
			$(LIBFTPATH)/ft_strncpy.o \
			$(LIBFTPATH)/ft_toupper.o \
			$(LIBFTPATH)/ft_itoa.o \
			$(LIBFTPATH)/ft_memcpy.o \
			$(LIBFTPATH)/ft_putstr.o \
			$(LIBFTPATH)/ft_striter.o \
			$(LIBFTPATH)/ft_strnequ.o \
			$(LIBFTPATH)/ft_lstadd.o \
			$(LIBFTPATH)/ft_memdel.o \
			$(LIBFTPATH)/ft_putstr_fd.o \
			$(LIBFTPATH)/ft_striteri.o \
			$(LIBFTPATH)/ft_strnew.o \
			$(LIBFTPATH)/ft_lstdel.o \
			$(LIBFTPATH)/ft_memmove.o \
			$(LIBFTPATH)/ft_strcat.o \
			$(LIBFTPATH)/ft_strjoin.o \
			$(LIBFTPATH)/ft_strnstr.o \
			$(LIBFTPATH)/ft_lstmap.o \
			$(LIBFTPATH)/ft_lstappend.o \
			$(LIBFTPATH)/ft_lstelem.o \
			$(LIBFTPATH)/ft_lstsize.o \
			$(LIBFTPATH)/ft_lstdelelem.o \
			$(LIBFTPATH)/ft_lstaddelem.o \
			$(LIBFTPATH)/get_next_line.o

NAME = libftprintf.a
CFLAGS = -c -Wall -Werror -Wextra
LIBFTPATH = libft

all: $(NAME)

$(NAME):
	@make -C $(LIBFTPATH)
	@gcc $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ) $(OBJ_libft)

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
