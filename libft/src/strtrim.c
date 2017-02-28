/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:38:09 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/22 12:27:37 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	char	*trim;

	if (s == NULL || ft_strlen(s) == 0)
		return (ft_strdup(s));
	beg = 0;
	while (s[beg] && (s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t'))
		beg++;
	if (beg == (int)ft_strlen(s))
	{
		if (!(trim = (char *)malloc(1)))
			return (NULL);
		trim[0] = '\0';
		return (trim);
	}
	end = ft_strlen(s) - 1;
	while (end >= 0 && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	if (!(trim = (char *)malloc(end - beg + 2)))
		return (NULL);
	ft_memcpy(trim, &s[beg], end - beg + 1);
	trim[end + 1] = '\0';
	return (trim);
}
