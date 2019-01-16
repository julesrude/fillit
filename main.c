#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h" //ne nada
#include "tetrominos.h"

int main(int argc, char const *argv[])
{
	t_tetromino **head;
	t_tetromino *temp;

	head = (t_tetromino **)malloc(sizeof(t_tetromino *));
	*head = NULL;
	if(argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
		read_file(fd, head);
		
		temp = *head;
		ft_putendl((temp)->figure[0]);
		ft_putendl((temp)->figure[1]);
		ft_putendl((temp)->figure[2]);
		ft_putendl((temp)->figure[3]);
		ft_putendl("\n");
		temp = temp->next;
		ft_putendl((temp)->figure[0]);
		ft_putendl((temp)->figure[1]);
		ft_putendl("\n");
		temp = temp->next;
		ft_putendl((temp)->figure[0]);
		ft_putendl((temp)->figure[1]);
	}
	system("leaks fillit");
	return 0;
}
