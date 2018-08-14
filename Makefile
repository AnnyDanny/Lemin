
NAME = lem-in
SRC = lem_in.c cle_s.c check_start_coord.c check_end_coord.c \
check_other_coord.c connect.c go_ants.c create_queue.c \
add_to_check_other.c add_to_start.c add_to_end.c check_to_lemin_one.c \
check_to_lemin_second.c
FLAGS = -Wall -Wextra -Werror -g
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