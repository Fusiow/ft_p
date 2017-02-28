/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:37:53 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 16:44:32 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s2);
	while (s1[i])
	{
		if (s1[i] == s2[0])
		{
			while (j < len && s1[i + j] == s2[j])
				j++;
			if (j == len)
				return ((char *)&(s1[i]));
		}
		j = 0;
		i++;
	}
	return (NULL);
}
