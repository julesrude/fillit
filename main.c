#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h" //ne nada
#include "tetrominos.h"


void	show_map(void)
{
	int			i;

	i = 0;
	while(i < map->size)
	{
		write(1, map->field[i], map->size);
		ft_putchar('\n');
		i++;
	}
}

void	show_tetra(t_tetromino *tetra)
{
	int			i;

	i = 0;
	while(i < (tetra)->height)
	{
		ft_putendl((tetra)->figure[i]);
		i++;
	}
	ft_putstr("\n");
}

int main(int argc, char const *argv[])
{
	t_tetromino *temp;
	
	head = (t_tetromino **)malloc(sizeof(t_tetromino *));
	*head = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	if(argc > 1)
	{
		int fd = open(argv[1], O_RDONLY);
		if(fd < 0 || read(fd, (void*)0, 0) < 0)
		{
			ft_putendl("error");
			return (0);
		}
		read_file(fd, head);
		temp = *head;
		/* дивимся, чи записалося в память*/
		while(temp)
		{
			show_tetra(temp);
			temp = temp->next;
		}
		create_map(ft_sqrtint(lst_tetro_size(*head) * 4) + 1);
		recursion(*head);

		show_map();
	}
	system("leaks fillit");
	return 0;
}
