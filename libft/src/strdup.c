/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:15:33 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 12:25:55 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, len);
	s[len] = '\0';
	return (s);
}
