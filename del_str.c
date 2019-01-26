/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:42:59 by mivasche          #+#    #+#             */
/*   Updated: 2019/01/26 19:30:30 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"

void	del_str_all(char **tetr, char *buff)
{
	int		ind;

	ind = 0;
	while (ind != 4 && tetr[ind])
	{
		ft_strdel(&tetr[ind]);
		ind++;
	}
	free(tetr);
	free(buff);
}
