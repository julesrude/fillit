/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:00:09 by mivasche          #+#    #+#             */
/*   Updated: 2019/01/10 16:13:55 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 5
# define MAX_FD_NUM 4096

# include "./libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
