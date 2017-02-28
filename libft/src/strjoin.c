/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:16:04 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/20 16:36:13 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(s, s1);
	ft_strcpy(&s[ft_strlen(s1)], s2);
	return (s);
}
