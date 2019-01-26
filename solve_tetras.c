/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:27:48 by yruda             #+#    #+#             */
/*   Updated: 2019/01/26 19:22:17 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"
#include "get_next_line.h"

/*
** plus_coords - Moves the tetra's further in the map
** zero_coords - Resets all the next tetras' to the start of the map
*/

int		plus_coords(t_tetromino *tetra)
{
	if (tetra->x < g_map->size - tetra->width)
		tetra->x++;
	else if (tetra->y < g_map->size - tetra->height)
	{
		tetra->y++;
		tetra->x = 0;
	}
	else
		return (0);
	return (1);
}

int		zero_coords(t_tetromino *tetra)
{
	while (tetra)
	{
		tetra->x = 0;
		tetra->y = 0;
		tetra = tetra->next;
	}
	return (1);
}

/*
** Tries to place ONE tetromino looking over the free places in the map.
** Looking over is starting from {y; x} from top to bottom, from left to right.
** [i, j] are the coordinates of the spot on the tetra we are trying to place.
*/

int		check_sharps(t_tetromino *tetra, char **current_map)
{
	int		y;
	int		x;
	int		k;
	int		l;

	y = tetra->y;
	x = tetra->x;
	k = -1;
	l = -1;
	while (++k < tetra->height)
	{
		while (++l < tetra->width)
		{
			if (!COMBINE(tetra->figure[k][l], current_map[y + k][x + l]))
			{
				if (!plus_coords(tetra))
					return (0);
				if (check_sharps(tetra, current_map))
					return (1);
				return (0);
			}
		}
		l = -1;
	}
	return (1);
}

/*
** place_tetras and recursion - Connected recursive functions,
** the heart of the algorithm
*/

int		place_tetras(t_tetromino *tetra)
{
	if (!tetra)
		return (1);
	if (check_sharps(tetra, g_map->field))
	{
		tetrato_map(tetra);
		if (place_tetras(tetra->next))
			return (1);
		else
		{
			reverse_map(tetra);
			if (plus_coords(tetra) && zero_coords(tetra->next))
				if (place_tetras(tetra))
					return (1);
		}
	}
	return (0);
}

int		recursion(void)
{
	if (!(*g_head))
		return (-1);
	if (place_tetras(*g_head))
		return (1);
	else
	{
		ft_arrdel((void **)g_map->field, g_map->size);
		free(g_map->field);
		create_map(g_map->size + 1);
		zero_coords(*g_head);
		recursion();
	}
	return (1);
}
