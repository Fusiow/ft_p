/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:05:52 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/20 16:15:42 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;

	s2 = (char *)malloc(len);
	ft_bzero(s2, len);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, &s[start], len);
	return (s2);
}
