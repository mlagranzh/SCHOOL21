NAME	=	push_swap
GCC		=	gcc -Wall -Wextra -Werror
LIBA	=	libft/
SRCS	=	main.c	operations.c simple_sort.c
OBJ		=	$(SRCS:.c=.o)
INCLUDE	=	.
OBJ_DIR	=	/.o

all: libft $(NAME)
#%(OBJ_DIR:.o): %.c $(INCLUDE)
#		$(GCC) -c $(SRCS) -I $(INCLUDE)
$(NAME): $(OBJ) 
	@echo "\033[0;35mСоздаю исполняемый файл...\033[0;32m"
	$(GCC) -o $(NAME) $(OBJ) -L $(LIBA) -lft
libft:
	@echo "\033[0;35mКомпилю libft... \033[0;32m"
	@make -C $(LIBA)
clean:
	@echo "\033[0;35mУдаляю объектные файлы...\033[0;31m"
	@make clean -C $(LIBA)
	rm -f $(OBJ)
fclean: clean
	@echo "\033[0;35mУдаляю исполняемый файл...\033[0;31m"
	rm -f $(NAME)
	@make fclean -C $(LIBA)
re: fclean all
.PHONY: all libft clean fclean re
