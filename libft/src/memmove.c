/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 15:22:31 by lbinet            #+#    #+#             */
/*   Updated: 2015/12/14 16:27:08 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p;
	const char	*d;
	char		*tmp;

	if (src == NULL || dst == NULL)
		return (NULL);
	d = src;
	p = dst;
	tmp = ft_strdup(d);
	ft_memcpy(p, tmp, len);
	free(tmp);
	return (dst);
}
