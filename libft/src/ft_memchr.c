/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:09:05 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/15 18:30:35 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	a;

	a = (unsigned char)c;
	i = 0;
	str = (unsigned char *)s;
	while (str[i] != a && i < (n - 1))
		i++;
	if (str[i] == a && n != 0)
		return (str += i);
	return (NULL);
}
