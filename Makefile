CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_count_len.c ft_strcat_format.c ft_printf.c get_hexa.c ft_strcat_one_char.c
OBJS = $(patsubst %.c, %.o, $(SRCS))
NAME = libftprintf.a
LIBFT = libft.a

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $(NAME) libft/$(LIBFT) $(OBJS)
$(LIBFT):
	make -C libft/
%.o:%.c $(FILES)
	$(CC) $(CFLAGS) -c $< -o $@ -I libft/includes -I. 
all: $(NAME)
clean:
	make -C libft/ clean
	rm -f $(OBJS)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
