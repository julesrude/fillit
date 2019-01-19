/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tetro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:10:47 by yruda             #+#    #+#             */
/*   Updated: 2019/01/16 16:10:49 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"
#include "get_next_line.h"

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
	if (!(new = (t_tetromino *)malloc(sizeof(t_tetromino))))
		return (NULL);
	new->x = 0;
	new->y = 0;
	new->figure = NULL;
	shape_analisys(shape, new); /* assigns w, h */
	new->next = NULL;
	return (new);
}

int		lst_tetro_size(t_tetromino *begin_list)
{
	int		i;
	t_tetromino	*t;

	i = 0;
	t = begin_list;
	while (t != NULL)
	{
		i++;
		t = t->next;
	}
	return (i);
}
