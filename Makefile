
NAME = lem-in
# HEADER = -c -I ./includes/
SRC = lem_in.c cle_s.c check_start_coord.c
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: liba $(NAME)

liba: 
	$(MAKE) -C ./libft

$(NAME):$(OBJ)
	@gcc -o $(NAME) $(OBJ) libft/libft.a

%.o: %.c
			@gcc $(FLAGS) -I libft/includes -c -o $@ $<

clean: libacl
			@rm -f *.o
libacl:
	$(MAKE) -C ./libft clean

fclean: libaclf clean
			@rm -f $(NAME)
libaclf:
	$(MAKE) -C ./libft fclean

re: fclean all