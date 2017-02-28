/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:48:06 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 17:08:20 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s2);
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[0])
		{
			while (i + j < n && s1[i + j] && s2[j] && s1[i + j] == s2[j])
				j++;
			if (j == len)
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
