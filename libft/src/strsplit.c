/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 16:53:53 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 12:27:36 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int		get_nb_words(const char *s, char c)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static int		ft_strlen_ic(const char *s, unsigned int i, char c)
{
	int			n;
	int			j;
	int			len;

	n = 0;
	j = 0;
	len = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
			n++;
		while (s[j] && s[j] != c)
		{
			if ((unsigned int)n == i)
				len++;
			j++;
		}
		if ((unsigned int)n == i)
			return (len);
	}
	return (len);
}

static int		get_split_index(const char *s, unsigned int i, char c)
{
	int			n;
	int			j;

	n = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
			n++;
		if ((unsigned int)n == i)
			return (j);
		while (s[j] && s[j] != c)
			j++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	int			n;

	if (s == NULL)
		return (NULL);
	n = get_nb_words(s, c);
	tab = (char **)malloc((n + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tab[i] = (char *)malloc(ft_strlen_ic(s, i + 1, c) + 1);
		if (tab[i] == NULL)
			return (NULL);
		ft_bzero(tab[i], ft_strlen_ic(s, i + 1, c) + 1);
		ft_memcpy(tab[i], &s[get_split_index(s, i + 1, c)],
					ft_strlen_ic(s, i + 1, c));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
