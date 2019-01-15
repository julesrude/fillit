/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:16:45 by yruda             #+#    #+#             */
/*   Updated: 2019/01/08 15:16:48 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 10
# define R_TOEND(fd, line) { while(get_next_line(fd, &text) == 1) {R_TOEND1} }
# define R_TOEND1 temp = line; if(line) line = ft_strjoin(line, text); R_TOEND2
# define R_TOEND2 else line = ft_strdup(text); free (temp); free (text);

int	get_next_line(const int fd, char **line);

#endif
