/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:00:26 by mivasche          #+#    #+#             */
/*   Updated: 2018/12/04 15:40:44 by mivasche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*a;
	int		i;

	i = 0;
	a = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (a)
	{
		while (src[i] != '\0')
		{
			a[i] = src[i];
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (0);
}
