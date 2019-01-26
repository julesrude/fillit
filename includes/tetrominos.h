/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrominos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:55:05 by yruda             #+#    #+#             */
/*   Updated: 2019/01/26 19:31:42 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETROMINOS_H
# define TETROMINOS_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>

typedef struct	s_tetromino
{
	int					width;
	int					height;
	char				**figure;
	int					y;
	int					x;
	struct s_tetromino	*next;
}				t_tetromino;

t_tetromino		**g_head;

typedef struct	s_map
{
	char		**field;
	int			size;
}				t_map;

t_map			*g_map;

# define COMBINE(a, b) ((a == '.' && b == '.') ? '.' : ((a == '.' COMBINE1(a, b)
# define COMBINE1(a, b) &&  b == '#') || (a == '#' && b == '.')) ? '#' : 0)

void			sharps_detector(char **shape, int **elems);
void			shape_analisys(char **shape, t_tetromino *new);
int				read_file(int fd);

int				check_sharps(t_tetromino *tetra, char **current_map);
int				place_tetras(t_tetromino *tetra);
int				recursion(void);

void			tetrato_map(t_tetromino *tetra);
void			reverse_map(t_tetromino *tetra);
void			create_map(int size);
void			show_map(void);
void			map_shapes(void);

void			lst_tetro_addfront(t_tetromino **head, t_tetromino *new);
void			lst_tetro_addback(t_tetromino **head, t_tetromino *new);
t_tetromino		*lst_tetro_new(char **shape);
int				lst_tetro_size(t_tetromino *begin_list);

int				ft_validation(char **tetrimino, int fd, int num_str,
					int end_tetr);
void			del_str_all(char **tetr, char *buff);

#endif
