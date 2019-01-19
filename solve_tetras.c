/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:27:48 by yruda             #+#    #+#             */
/*   Updated: 2019/01/16 20:28:01 by yruda            ###   ########.fr       */
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

#define COMBINE(a, b) ((a == '.' && b == '.') ? '.' : ((a == '.' COMBINE1(a, b)
#define COMBINE1(a, b) &&  b == '#') || (a == '#' && b == '.')) ? '#' : 0)

/*
** Tries to place the tetromino looking over the free places in the map.  -!!!!NO!!!!-
** Looking over is starting from {x; y} from top to bottom, from left to right.
** [i, j] are the coordinates of the spot on the tetra we are trying to place.
*/

int		check_sharps(t_tetromino *tetra, char **current_map, int size, int i, int j)
{
	int	x = tetra->x;
	int	y = tetra->y;
	int	k = 0;
	int	l = 0;
	int	check = 0;

	i = 0;
	j = 0;
	while (k < tetra->height)
	{
		while (l < tetra->width)
		{
			if(COMBINE(tetra->figure[k][l], current_map[x + k][y + l]))
				check++;
			else
			{
				printf(COLOR_MAGENTA "______i'm plusing______" COLOR_RESET);
				if(tetra->y < size)
					tetra->y++;
				else if (tetra->x < size)
				{	
					tetra->x++;
					tetra->y = 0;
				}
				check_sharps(tetra, current_map, map->size, 0, 0);
				return 0;
				
			}
			l++;
		}
		l = 0;
		k++;
	}
	/* to the map */
	while(i < tetra->height)
	{
		while(j < tetra->width)
		{
			map->field[tetra->x + i][tetra->y + j] = tetra->figure[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	if(check == tetra->width * tetra->height)
	{
		printf(COLOR_MAGENTA "______COOL______\n" COLOR_RESET);
	}
	return (1);
}

int		place_tetra(t_tetromino *tetra, int size)
{
	size = 4;
	printf(COLOR_RED "HEY" COLOR_RESET);
	if(!tetra)
		return(1);
	printf(COLOR_RED "HEY2" COLOR_RESET);
	if(!check_sharps(tetra, map->field, map->size, 0, 0))
		return(0);
	printf(COLOR_RED "HEY3" COLOR_RESET);
	if(place_tetra(tetra->next, map->size))
		return (1);
	return(1);
}

void	create_map(int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->size = size;
	map->field = (char **)malloc(size * sizeof(char *));
	while(i < size)
	{
		map->field[i] = (char *)malloc(size * sizeof(char));
		while(j < size)
		{
			map->field[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

int		recursion(t_tetromino *tetra)
{
	/*int i = 0;
	int j = 0;*/
	if(!tetra)
		return(42);

	place_tetra(tetra, map->size);
/*	check_sharps(tetra, ft_arrdup(map->field, map->size, map->size), map->size, 0, 0);
	
	show_tetra(tetra);
	show_map();
	ft_putchar('\n');
	
	i = 0;
	j = 0;
	tetra = tetra->next;
	check_sharps(tetra, ft_arrdup(map->field, map->size, map->size), map->size, 0, 0);
	while(i < tetra->height)
	{
		while(j < tetra->width)
		{
			map->field[tetra->x + i][tetra->y + j] = tetra->figure[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	show_tetra(tetra);
	show_map();
	ft_putchar('\n');*/

	/*if(place_tetra(tetra, ft_arrdup(map->field, map->size, map->size), map->size))
	{
		recursion(tetra->next);
		show_tetra(tetra);
		show_map();
		ft_putchar('\n');
	}*/
	return 0;
}

int		solve_tetra(t_tetromino *tetra)
{
	int		minimal_map;

	tetra = *head; // shit
	minimal_map = ft_sqrtint(lst_tetro_size(*head) * 4) + 1;
	create_map(minimal_map);
	return (minimal_map);
}
