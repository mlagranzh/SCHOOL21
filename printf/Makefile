NAME		= libftprintf.a
SRCS	= ft_create_and_parse.c ft_printf_hexadecimal.c ft_printf_string.c ft_printf_decimal.c ft_printf_char.c ft_printf_unsigned.c ft_printf.c ft_utils_0.c ft_utils_1.c

OBJS	= $(SRCS:.c=.o)
GCC	= gcc -Wall -Wextra -Werror
.c.o :
	${GCC} -c $< -o ${<:.c=.o}
$(NAME): ${OBJS}
	make -C Libft
	cp libft/libft.a ./$(NAME)
	ar -rcs $(NAME) $(OBJS)
all: $(NAME)
fclean: clean
	rm -f $(NAME)
clean:
	rm -f $(OBJS)
re: fclean all
.PHONY: all clean fclean re .c.o