/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:42:59 by mivasche          #+#    #+#             */
/*   Updated: 2019/02/21 18:44:54 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetrominos.h"

int		del_str(char **tetr, char *buff)
{
	int		ind;

	ind = 0;
	while (ind < 4)
	{
		ft_strdel(&tetr[ind]);
		ind++;
	}
	free(tetr);
	if (buff)
		ft_strdel(&buff);
	return (0);
}
