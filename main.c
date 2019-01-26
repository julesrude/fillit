/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 13:12:40 by yruda             #+#    #+#             */
/*   Updated: 2019/01/26 19:27:38 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "tetrominos.h"

/*
** calculating size of the square map neccesary to hold the given tetrominos
*/

int		min_map(void)
{
	t_tetromino	*tetra;
	int			minimal_size;
	int			max_height;
	int			max_width;

	max_height = 0;
	max_width = 0;
	tetra = *g_head;
	minimal_size = ft_sqrtint(lst_tetro_size(*g_head) * 4);
	if (lst_tetro_size(*g_head) >= 4)
		return (minimal_size);
	while (tetra)
	{
		if (tetra->height > max_height)
			max_height = tetra->height;
		if (tetra->width > max_width)
			max_width = tetra->width;
		tetra = tetra->next;
	}
	if (max_width >= max_height && max_width >= minimal_size)
		return (max_width);
	if (max_height >= max_width && max_height >= minimal_size)
		return (max_height);
	return (minimal_size);
}

void	usage(void)
{
	ft_putendl("[usage]:	./fillit file_with_tetrominos");
	ft_putendl("[file format]:	file contains a list of Tetrominos");
	ft_putendl("[Tetrominos]:	every Tetromino must exactly fit in a 4 x 4 \
chars square and all Tetrimino are separated by an newline each. \
A Tetrimino is a classic piece of Tetris composed of 4 blocks \
(marked by '#'). Examples:");
	ft_putendl("....    ....    ####    ....    .##.    ....    .#..    ....");
	ft_putendl("..##    ....    ....    ....    ..##    .##.    ###.    ##..");
	ft_putendl("..#.    ..##    ....    ##..    ....    ##..    ....    #...");
	ft_putendl("..#.    ..##    ....    ##..    ....    ....    ....    #...");
}

int		main(int argc, char const *argv[])
{
	char		**t;
	int			fd;

	t = NULL;
	g_head = (t_tetromino **)malloc(sizeof(t_tetromino *));
	*g_head = NULL;
	g_map = (t_map *)malloc(sizeof(t_map));
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0 || read(fd, (void*)0, 0) < 0 || !ft_validation(t, fd, -1, 0))
		{
			ft_putendl("error");
			return (0);
		}
		fd = open(argv[1], O_RDONLY);
		read_file(fd);
		create_map(min_map());
		recursion();
		map_shapes();
		show_map();
	}
	else
		usage();
	return (0);
}
