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

void		lst_tetro_addback(t_tetromino **head, t_tetromino *new)
{
	t_tetromino	**temp;

	temp = NULL;
	if (head == NULL || new == NULL)
		return ;
	temp = head;
	while (*temp != NULL)
		temp = &(*temp)->next;
	(*temp) = new;
}

t_tetromino	*lst_tetro_new(char **shape)
{
	t_tetromino *new;
	int			i;

	new = NULL;
	i = 0;
	if (!shape || !*shape)
		return (NULL);
	if (!(new = (t_tetromino *)malloc(sizeof(t_tetromino))))
		return (NULL);
	new->figure = (char **)malloc(4 * sizeof(char *));
	while (i < 4)
	{
		new->figure[i] = shape[i];
		i++;
	}
	free(shape); //fdsflfsklhjsfghghklsgjhkgdjhjhsfd
	new->width = 0;
	new->height = 0;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char		**shape_correction(char **shape)
{
	char		**result;
	int			height;
	int			i;

	height = 4;
	i = 0;
	result = (char **)malloc(height * sizeof(char *));
	while(i < 4)
	{
		result[i] = shape[i];
		i++;
	}
	printf(COLOR_YELLOW "%p\n" COLOR_RESET, shape[3]);
	return (result);
}

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
			tetro = lst_tetro_new(shape_correction(shape)); //somethong to modify here to make the 
			printf(COLOR_YELLOW "%p\n" COLOR_RESET, tetro);			
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
