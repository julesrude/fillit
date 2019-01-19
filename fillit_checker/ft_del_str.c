/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:42:59 by mivasche          #+#    #+#             */
/*   Updated: 2019/01/16 18:43:02 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void	ft_del_str(char **tetr)
{
	int		ind;

	ind = 0;
	while (ind < 4 && tetr[ind])
	{
		ft_strdel(&tetr[ind]);
		ind++;
	}
}

void	ft_del_int(int **tetr, int ind_save)
{
	int		ind;

	ind = 0;
	if (!tetr)
		return ;
	while (ind < ind_save)
	{
		free(tetr[ind]);
		tetr[ind] = NULL;
		ind++;
	}
}
