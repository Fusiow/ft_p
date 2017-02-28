/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:36:05 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/22 16:30:44 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;
	size_t		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = s;
	while (i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
			return ((void *)&(p[i]));
		i++;
	}
	return (NULL);
}
