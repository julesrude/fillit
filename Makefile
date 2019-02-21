NAME = fillit
FUNCS = main.c read_tetras.c lst_tetro.c solve_tetras.c validation.c del_str.c map_operations.c
OBJ = $(FUNCS:.c=.o)
HEADER = includes/

LIBFT_HEAD = libft/includes/
LIBFT = libft/libft.a

all :$(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@gcc -Wall -Wextra -Werror $(FUNCS) $(LIBFT) -I $(LIBFT_HEAD) -I $(HEADER) -o $(NAME)
	@echo "[ $(NAME) created ]"

%.o: %.c $(HEADER)
	@gcc -Wall -Wextra -Werror  -I $(LIBFT_HEAD) -I $(HEADER) -c $< -o $@

$(LIBFT):
	@make -C libft
	@echo "[ $(LIBFT) created ]"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "[ objects cleaned ]"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "[ $(NAME) and $(LIBFT) cleaned ]"

re: fclean all