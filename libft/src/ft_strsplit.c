/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 16:05:47 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/15 18:04:30 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**countword(char const *s, char c)
{
	int		i;
	int		count;
	char	**tab;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			++i;
		while (s[i] != c && s[i] != '\0')
			++i;
		if ((s[i] == c && s[i - 1] != c) || (s[i] != c && s[i + 1] == '\0'))
			++count;
	}
	if ((tab = malloc(sizeof(char *) * count + 1)) == NULL)
		return (NULL);
	return (tab);
}

char**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s || !c || (tab = countword(s, c)) == NULL)
		return (0);
	i = j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			if ((tab[j++] = ft_strsub(s, i, len)) == NULL)
				return (NULL);;
			i = i + len;
		}
	}
	tab[j] = NULL;
	return (tab);
}
