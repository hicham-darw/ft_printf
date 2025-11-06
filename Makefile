CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = libftprintf.h

SRCS = ft_address_cat.c ft_memset.c ft_strlen.c ft_itoa.c ft_charcat.c ft_decimal_cat.c ft_get_string.c ft_hexadecimal_cat.c \
       ft_printf.c ft_strcat.c ft_uitoa.c get_len_printf.c printf_not_completed.c len_hexa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
