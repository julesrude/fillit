#ifndef TETROMINOS_H
#define TETROMINOS_H

#include "libft.h"
#include <stdlib.h>

typedef struct	s_tetromino
{
	int					width;
	int					height;
	char				**figure;
	int					x;
	int					y;
	struct s_tetromino	*next;
}				t_tetromino;

int			read_file (int fd, t_tetromino **head);

void 		lst_tetro_addback(t_tetromino **head, t_tetromino *new);
t_tetromino *lst_tetro_new (char **shape);

#endif