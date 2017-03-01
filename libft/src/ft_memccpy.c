/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:33:04 by rkharif           #+#    #+#             */
/*   Updated: 2016/10/17 18:05:34 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*strd;
	char	*strs;

	if (n)
	{
		strd = (char *)dst;
		strs = (char *)src;
		while (n && *strs != c)
		{
			*strd++ = *strs++;
			n--;
		}
		if (*strs == c)
		{
			*strd = *strs;
			return (strd + 1);
		}
	}
	return (0);
}
