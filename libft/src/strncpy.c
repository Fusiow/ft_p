/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:30:54 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/22 13:59:53 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	len;

	if (src == NULL || dst == NULL)
		return (NULL);
	ft_memccpy(dst, src, '\0', n);
	len = (ft_strlen(src) < n) ? ft_strlen(src) : n;
	ft_memset(&dst[len], 0, len);
	return (dst);
}
