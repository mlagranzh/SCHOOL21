NAME		= libftprintf.a
SRCS	= ft_create_and_parse.c ft_printf_specificator.c ft_printf.c

OBJS	= $(SRCS:.c=.o)
GCC	= gcc
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