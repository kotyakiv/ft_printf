# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykot <ykot@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 23:20:01 by ykot              #+#    #+#              #
#    Updated: 2021/12/08 16:55:02 by ykot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_lstdelone.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strrchr.c \
ft_bzero.c ft_lstiter.c ft_putchar.c ft_strclr.c ft_strlen.c ft_strsplit.c \
ft_isalnum.c ft_lstnew.c ft_putchar_fd.c ft_strcmp.c ft_strmap.c ft_strstr.c \
ft_isalpha.c ft_memalloc.c ft_putendl.c ft_strcpy.c ft_strmapi.c ft_strsub.c \
ft_isascii.c ft_memccpy.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c \
ft_isdigit.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c ft_tolower.c \
ft_isprint.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c ft_strncpy.c ft_toupper.c \
ft_itoa.c ft_memcpy.c ft_putstr.c ft_striter.c ft_strnequ.c ft_lstadd.c \
ft_memdel.c ft_putstr_fd.c ft_striteri.c ft_strnew.c ft_lstdel.c ft_memmove.c \
ft_strcat.c ft_strjoin.c ft_strnstr.c ft_lstmap.c ft_lstappend.c ft_lstelem.c \
ft_lstsize.c ft_lstdelelem.c ft_lstaddelem.c get_next_line.c

OBJ = $(SRC:.c=.o)
NAME = libft.a
CFLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
