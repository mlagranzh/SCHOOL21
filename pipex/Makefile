NAME	=	pipex

FLAGS	=	

CC		=	gcc $(FLAGS) -g

LIBFT	=	-L$(DLIB) -lft

DLIB	=	libft/

DINC	=	-I./ -I./libft/

DSRC	=	./

DOBJ	=	objs/

SRC		=	pipex.c	

OBJ		=	$(patsubst %.c, $(DOBJ)%.o, $(SRC))

RMF		=	/bin/rm -f

RMD		=	/bin/rm -Rf

MKD		=	/bin/mkdir -p

all: libft $(NAME)

$(DOBJ)%.o: $(DSRC)%.c
	@$(MKD) $(DOBJ)
	@echo "Compilation de l'objet:\033[0;32m"
	$(CC) -o $@ -c $< $(DINC)
	@echo "\033[0;m\c"

$(NAME): $(DLIB)libft.a $(OBJ)
	@echo "Creation de l'executable:\033[0;32m"
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\033[0;m\c"

clean:
	@echo "Suppression des objets du projet:\033[0;31m"
	$(RMF) $(OBJ)
	@echo "\033[0;m\c"
	@$(RMD) $(DOBJ)

fclean: clean
	@echo "Suppression de l'executable\033[0;31m"
	$(RMF) $(NAME)
	@echo "\033[0;m\c"

libft:
	@echo "Compilation des sources de la lib:"
	@make -C $(DLIB)

re: fclean all

.PHONY: all libft clean fclean re
