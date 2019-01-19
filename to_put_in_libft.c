/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_put_in_libft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 20:29:42 by yruda             #+#    #+#             */
/*   Updated: 2019/01/16 20:29:47 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"
#include "get_next_line.h"
#include "libft.h"

int		ft_maxarr(int *a, int n)
{
	int max;
	int	i;

	i = 1;
	max = *a;
	while (i < n)
	{
		if (max < a[i])
			max = a[i];
		i++;
	}
	return (max);
}

int		ft_minarr(int *a, int n)
{
	int min;
	int	i;

	i = 1;
	min = *a;
	while (i < n)
	{
		if (min > a[i])
			min = a[i];
		i++;
	}
	return (min);
}

/*
** frees elements of a 2-story array
*/

void	ft_arrfree(void **arr, int elems)
{
	int	i;

	i = 0;
	while (i < elems)
	{
		free(arr[i]);
		i++;
	}
}

int		ft_sqrtint(unsigned int i)
{
	unsigned int	root;

	root = 0;
	while(root * root <= i)
		root++;
	return(root - 1);
}

char	**ft_arrdup(char **arr, int height, int width)
{
	char	**copy;
	int		i;

	i = 0;
	copy = NULL;
	if (arr == NULL)
		return (NULL);
	if((copy = (char **)malloc(sizeof(char*) * height)))
	{
		while(i < height)
		{
			copy[i] = (char *)malloc(sizeof(char) * width);
			ft_memcpy(copy[i], arr[i], width);
			i++;
		}
	}
	return (copy);
}
