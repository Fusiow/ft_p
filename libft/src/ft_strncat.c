/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:28:27 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/13 15:09:24 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		s1len;
	int		len;

	i = 0;
	s1len = ft_strlen(s1);
	len = ft_strlen((char *)s2) + s1len;
	while (s1len < len && (int)n > 0)
	{
		s1[s1len] = s2[i];
		i++;
		s1len++;
		n--;
	}
	s1[s1len] = '\0';
	return (s1);
}
