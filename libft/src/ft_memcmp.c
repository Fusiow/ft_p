/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:19:05 by rkharif           #+#    #+#             */
/*   Updated: 2016/10/17 15:26:16 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*sp1;
	char	*sp2;

	sp1 = (char *)s1;
	sp2 = (char *)s2;
	if (n == 0)
		return (0);
	while (--n && s1 && s2 && *sp1 == *sp2)
	{
		sp1++;
		sp2++;
	}
	return ((unsigned char)*sp1 - (unsigned char)*sp2);
}
