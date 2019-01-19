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

t_tetromino **head;

typedef struct	s_map
{
	char				**field;
	int					size;
}				t_map;

t_map		*map;

void		dots_detector(char **shape, int **elems);
void		shape_analisys(char **shape, t_tetromino *new);
int			read_file (int fd, t_tetromino **head);
int			check_sharps(t_tetromino *tetra, char **current_map, int size, int i, int j);
int			place_tetra(t_tetromino *tetra, int size);
int			recursion(t_tetromino *tetra);
int			solve_tetra(t_tetromino *tetra);
void		create_map(int size);

void 		lst_tetro_addback(t_tetromino **head, t_tetromino *new);
t_tetromino	*lst_tetro_new(char **shape);
int			lst_tetro_size(t_tetromino *begin_list);

int			ft_maxarr(int *a, int n);
int			ft_minarr(int *a, int n);
void		ft_arrfree(void **arr, int elems);
int			ft_sqrtint(unsigned int i);
char		**ft_arrdup(char **arr, int height, int width);

void		show_map(void);
void		show_tetra(t_tetromino *tetra);

#endif