/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:38:42 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/13 15:09:09 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*tmp1;
	char	*tmp2;
	int		len;
	
	if (*s2 == '\0')
		return ((char *)s1);
	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	len = ft_strlen(tmp2);
	i = 0;
	while (tmp1[i] != '\0' && (i + len) <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
		{
			return (tmp1 + i);
		}
		i++;
	}
	return (NULL);
}
