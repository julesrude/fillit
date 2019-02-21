/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:02:38 by yruda             #+#    #+#             */
/*   Updated: 2019/02/21 18:55:36 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"
#include "get_next_line.h"

#define HIGH	hashes[0][0]
#define LOW		hashes[0][3]

/*
** Detects sharps "#" in the shape (4x4 square) and records their
** addresses to "int **hashes"
*/

void		sharps_detector(char **shape, int **hashes)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	hashes[0] = (int *)malloc(4 * sizeof(int));
	hashes[1] = (int *)malloc(4 * sizeof(int));
	while (i < 4)
	{
		while (j < 4)
		{
			if (shape[i][j] == '#')
			{
				hashes[0][k] = i;
				hashes[1][k] = j;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*
** Makes subrectangle from the 4x4 square.
** Writes "width", "height" and "figure" to the tetrimino.
*/

void		shape_analisys(char **shape, t_tetromino *new)
{
	int			**hashes;
	int			left;
	int			right;
	int			i;
	int			j;

	i = -1;
	j = -1;
	hashes = (int **)malloc(2 * sizeof(int *));
	sharps_detector(shape, hashes);
	left = ft_minarr(hashes[1], 4);
	right = ft_maxarr(hashes[1], 4);
	new->height = LOW - HIGH + 1;
	new->width = right - left + 1;
	new->figure = (char **)malloc(new->height * sizeof(char *));
	while (++i < new->height)
	{
		new->figure[i] = (char *)malloc(new->width * sizeof(char));
		while (++j < new->width)
			new->figure[i][j] = shape[HIGH + i][left + j];
		j = -1;
	}
	ft_arrdel((void **)shape, 4);
	ft_arrdel((void **)hashes, 2);
	free(hashes);
}

/*
** Takes fd, launches cycle for every tetromino to
** write it into list.
*/

int			read_file(int fd)
{
	t_tetromino	*tetro;
	char		*line;
	char		*shape[4];
	int			i;
	int			j;

	i = 0;
	j = 0;
	while ((j = get_next_line(fd, &line)) > -1)
	{
		if (j == 0 || *line == '\0')
		{
			tetro = lst_tetro_new(shape);
			lst_tetro_addback(g_head, tetro);
			if (j == 0)
				break ;
			free(line);
			i = 0;
			continue ;
		}
		shape[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (1);
}
