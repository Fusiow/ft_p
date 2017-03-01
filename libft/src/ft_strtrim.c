/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:28:12 by rkharif           #+#    #+#             */
/*   Updated: 2016/10/17 15:42:34 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*str;
	unsigned int		i;
	unsigned int		j;

	if (!s || !*s)
		return ((char *)s);
	j = ft_strlen(s);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j >= i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0'))
		j--;
	if (i == 0 && j == ft_strlen(s))
		return ((char *)s);
	if ((str = ft_strsub(s, i, j - i + 1)) == NULL)
		return (NULL);
	return (str);
}
