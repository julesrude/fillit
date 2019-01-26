/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:41:43 by mivasche          #+#    #+#             */
/*   Updated: 2019/01/26 19:31:12 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"

int			ft_diff_num(int a, int b, int c, int d)
{
	return ((a == c && (b - d == 1 || d - b == 1)) || (b == d && (c - a == 1 ||
		a - c == 1)));
}

int			ft_check_connect(int **tetr)
{
	int		ind_a;
	int		ret_num;
	int		ind_i;

	ind_i = 0;
	ret_num = 0;
	while (ind_i < 4)
	{
		ind_a = 0;
		while (ind_a < 4)
		{
			if (ind_i != ind_a)
				ret_num += ft_diff_num(tetr[ind_i][0], tetr[ind_i][1],
					tetr[ind_a][0], tetr[ind_a][1]);
			ind_a++;
		}
		ind_i++;
	}
	return (ret_num);
}

int			ft_tetrimino_connect(char **tetr, int ind, int cha, int ind_save)
{
	int		count;
	int		**save_cha;

	save_cha = (int **)malloc(sizeof(int *) * 5);
	while (ind < 4 && tetr[ind])
	{
		while (tetr[ind][++cha])
		{
			if (tetr[ind][cha] == '#')
			{
				save_cha[ind_save] = (int *)malloc(sizeof(int) * 3);
				save_cha[ind_save][0] = ind;
				save_cha[ind_save][1] = cha;
				save_cha[ind_save][2] = '\0';
				ind_save++;
			}
		}
		cha = -1;
		ind++;
	}
	count = ft_check_connect(save_cha);
	ft_arrdel((void **)save_cha, 4);
	free(save_cha);
	ft_arrdel((void **)tetr, 4);
	return (count == 6 || count == 8 ? 1 : 0);
}

int			ft_valid_file(char **tetr, int index, int index_char)
{
	int		dot;
	int		sharp;

	dot = 0;
	sharp = 0;
	while (*tetr != NULL && index < 4 && tetr[index])
	{
		if (ft_strlen(tetr[index]) != 4)
			break ;
		while (tetr[index][index_char])
		{
			if (tetr[index][index_char] == '.')
				dot++;
			if (tetr[index][index_char] == '#')
				sharp++;
			index_char++;
		}
		index_char = 0;
		index++;
	}
	if (dot != 12 || sharp != 4 || ft_tetrimino_connect(tetr, 0, -1, 0) != 1)
		return (0);
	return (1);
}

int			ft_validation(char **tetr, int fd, int num_str, int end_tetr)
{
	char	*buff;
	int		check;

	check = 0;
	tetr = (char **)malloc(sizeof(char *) * 4);
	*tetr = NULL;
	while ((get_next_line(fd, &buff)))
	{
		if (++num_str == 5)
		{
			del_str_all(tetr, buff);
			return (0);
		}
		if (buff[0] != 0)
			tetr[num_str] = ft_strdup(buff);
		else
		{
			check++;
			(ft_valid_file(tetr, 0, 0)) == 1 ? end_tetr++ : 0;
			num_str = -1;
		}
		free(buff);
	}
	(ft_valid_file(tetr, 0, 0)) == 1 ? end_tetr++ : 0;
	free(tetr);
	return ((end_tetr == (check + 1)) ? 1 : 0);
}
