/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:08:51 by mivasche          #+#    #+#             */
/*   Updated: 2019/01/18 15:31:51 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_FILLIT_H
# define __FT_FILLIT_H

# include "get_next_line.h"
# include <fcntl.h>
# include "./libft/libft.h"

int		ft_fillit(char **tetrimino, int fd, int num_str, int end_tetr);
void	ft_del_str(char **tetr);
void	ft_del_int(int **tetr, int ind_save);

#endif
