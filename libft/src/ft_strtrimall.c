/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrimall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:43:50 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 16:15:26 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strtrimall(char const *s)
{
	int		start;
	int		end;
	char	*str;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = 0;
	while (s[start]
			&& (s[start] == ' ' || s[start] == '\t' || s[start] == '\n'
			|| s[start] == '\r' || s[start] == '\v' || s[start] == '\f'))
		start++;
	end = ft_strlen(s) - 1;
	while (end >= 0
			&& (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'
			|| s[end] == '\r' || s[end] == '\v' || s[end] == '\f'))
		end--;
	if (end == -1)
		end++;
	str = (char *)malloc(end - start + 2);
	ft_bzero(str, end - start + 2);
	ft_memcpy(str, &s[start], end - start + 1);
	return (str);
}
