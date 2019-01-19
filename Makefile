NAME = fillit
FUNCS = main.c read_tetras.c to_put_in_libft.c lst_tetro.c solve_tetras.c
OBJ = $(FUNCS:.c=.o)
HEADER = includes/

LIBFT_HEAD = libft/includes/
LIBFT = libft/libft.a

all :$(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	gcc -Wall -Wextra -Werror $(FUNCS) $(LIBFT) -I $(LIBFT_HEAD) -I $(HEADER) -o $(NAME)
	@echo ">> $(NAME) created"

%.o: %.c $(HEADER)
	gcc -Wall -Wextra -Werror  -I $(LIBFT_HEAD) -I $(HEADER) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all