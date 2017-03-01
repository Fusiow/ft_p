/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:28:24 by rkharif           #+#    #+#             */
/*   Updated: 2016/10/17 15:45:40 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	slen;

	slen = ft_strlen(s);
	while (s[slen] != c)
	{
		if (slen == 0)
			return (0);
		slen--;
	}
	return ((char *)&s[slen]);
}
