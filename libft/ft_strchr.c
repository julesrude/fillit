/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.unit.ua>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:35:36 by yruda             #+#    #+#             */
/*   Updated: 2018/11/22 18:50:31 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		if (*s++)
			continue ;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}