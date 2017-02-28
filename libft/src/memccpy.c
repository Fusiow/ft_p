/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:17:18 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 16:04:46 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*p;
	const char	*d;
	size_t		i;

	if (src == NULL || dst == NULL)
		return (NULL);
	p = dst;
	d = src;
	i = 0;
	while (i < n)
	{
		p[i] = d[i];
		if (d[i] == c)
			return (&(p[i + 1]));
		i++;
	}
	return (NULL);
}
