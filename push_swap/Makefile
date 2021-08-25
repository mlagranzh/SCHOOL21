NAME	=	push_swap
GCC		=	gcc -Wall -Wextra -Werror
SRCS	=	main.c	operations.c simple_sort.c advanced_sort.c utils0.c utils1.c utils2.c
OBJ		=	$(SRCS:.c=.o)
HEADER	=	push_swap.h	

all: $(NAME)
%.o: %.c $(HEADER)
	@echo "\033[0;35mКомпилю...\033[0;32m"
	$(GCC) -I $(HEADER) -c $< -o $@
$(NAME): $(OBJ) 
	@echo "\033[0;35mСоздаю исполняемый файл...\033[0;32m"
	$(GCC) -o $(NAME) -I $(HEADER) $(OBJ)
clean:
	@echo "\033[0;35mУдаляю объектные файлы...\033[0;31m"
	rm -f $(OBJ)
fclean: clean
	@echo "\033[0;35mУдаляю исполняемый файл...\033[0;31m"
	rm -f $(NAME)
re: fclean all
.PHONY: all libft clean fclean re
