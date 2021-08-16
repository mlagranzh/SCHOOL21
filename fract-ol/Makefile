NAME	=	fract-ol
GCC	=	gcc -Wall -Wextra -Werror
LIBA	=	minilibx/
SRCS	=	fract-ol.c	
OBJ	=	$(SRCS:.c=.o)

all: libft $(NAME)
$(NAME): $(OBJ)
	@echo "\033[0;35mСоздаю исполняемый файл...\033[0;32m"
	$(GCC) -o $(NAME) $(OBJ) -lmlx -L $(LIBA) -framework OpenGL -framework AppKit

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
