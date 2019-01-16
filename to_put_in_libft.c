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
