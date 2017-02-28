/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:38:48 by lbinet            #+#    #+#             */
/*   Updated: 2015/02/03 12:48:45 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char	*strreverse(char *s)
{
	char	*cp;
	int		len;
	int		i;

	cp = (char *)malloc(ft_strlen(s) + 1);
	if (cp == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	while (len >= 0)
	{
		cp[i] = s[len];
		len--;
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

static int	get_int_length(int nb)
{
	int		i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		test;

	if (n == 0)
	{
		s = ft_strnew(2);
		s[0] = '0';
		return (s);
	}
	test = (n < 0) ? 1 : 0;
	s = (char *)malloc(get_int_length(n) + 1 + test);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		s[i++] = ft_abs((n % 10)) + '0';
		n /= 10;
	}
	if (test)
		s[i] = '-';
	s[i + test] = '\0';
	s = strreverse(s);
	return (s);
}
