/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 21:02:38 by yruda             #+#    #+#             */
/*   Updated: 2019/01/15 21:02:41 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"
#include "get_next_line.h"

#include <stdio.h>
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define HIGH	hashes[0][0]
#define LOW		hashes[0][3]

/*
** Detects hashtags "#" in the shape (4x4 square) and records their
** addresses to "int **hashes"
*/

void		dots_detector(char **shape, int **hashes)
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
	dots_detector(shape, hashes);
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
	ft_arrfree((void **)shape, 4);
	ft_arrfree((void **)hashes, 2);
	free(hashes);
}

/*
** Takes fd, launches cycle for every tetromino to
** write it into list.
*/

int			read_file(int fd, t_tetromino **head)
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
			lst_tetro_addback(head, tetro);
			free(line);
			if (j == 0)
				break ;
			i = 0;
			continue ;
		}
		shape[i] = ft_strdup(line);
		free(line);
		i++;
	}
	return (1);
}
