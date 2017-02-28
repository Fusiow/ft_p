/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:56:21 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 12:24:55 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ft_memcpy(&(s1[len1]), s2, len2);
	s1[len1 + len2] = '\0';
	return (s1);
}
