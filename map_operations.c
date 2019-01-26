/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:15:39 by yruda             #+#    #+#             */
/*   Updated: 2019/01/26 19:34:13 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"

/*
** Writing the placed shapes to the global map
*/

void	tetrato_map(t_tetromino *tetra)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (tetra == NULL)
		return ;
	while (i < tetra->height)
	{
		while (j < tetra->width)
		{
			g_map->field[tetra->y + i][tetra->x + j] = COMBINE(g_map->field
				[tetra->y + i][tetra->x + j], tetra->figure[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
}

/*
** Taking tetra back from map (replacing '#' with '.')
*/

void	reverse_map(t_tetromino *tetra)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (tetra == NULL)
		return ;
	while (i < tetra->height)
	{
		while (j < tetra->width)
		{
			if (tetra->figure[i][j] == '#')
				g_map->field[tetra->y + i][tetra->x + j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

/*
** Creates EMPTY map of the given size
*/

void	create_map(int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g_map->size = size;
	g_map->field = (char **)malloc(size * sizeof(char *));
	while (i < size)
	{
		g_map->field[i] = (char *)malloc(size * sizeof(char));
		while (j < size)
		{
			g_map->field[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

/*
** putting the map to the standart output
*/

void	show_map(void)
{
	int			i;

	i = 0;
	while (i < g_map->size)
	{
		write(1, g_map->field[i], g_map->size);
		ft_putchar('\n');
		i++;
	}
}

/*
** filling the map with tetrominos according to the [x;y] coordinates
** of their place in the map, and their order (first is 'A', second - 'B', ...)
*/

void	map_shapes(void)
{
	int			count;
	int			i;
	int			j;
	t_tetromino	*tetra;

	count = 0;
	i = -1;
	j = -1;
	tetra = *g_head;
	while (tetra)
	{
		i = -1;
		j = -1;
		while (++i < tetra->height)
		{
			while (++j < tetra->width)
			{
				if (tetra->figure[i][j] == '#')
					g_map->field[tetra->y + i][tetra->x + j] = 'A' + count;
			}
			j = -1;
		}
		tetra = tetra->next;
		count++;
	}
}
