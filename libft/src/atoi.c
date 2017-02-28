/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 09:53:26 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 16:15:53 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static int	ft_ipow(int n, int p)
{
	int		i;
	int		res;

	if (n == 0)
		return (0);
	if (p == 0)
		return (1);
	res = n;
	i = 1;
	while (i < p)
	{
		res *= n;
		i++;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		p;
	int		sign;
	int		res;
	char	*s;

	if (str == NULL)
		return (0);
	s = ft_strtrimall(str);
	i = 0;
	sign = 0;
	if (s[0] == '+' || s[0] == '-')
	{
		i = 1;
		sign = (s[0] == '+') ? 0 : 1;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		i++;
	p = 0;
	res = 0;
	i = (i > 0) ? i - 1 : i;
	while (i >= 0 && s[i] >= '0' && s[i] <= '9')
		res += (s[i--] - '0') * ft_ipow(10, p++);
	res = (sign == 0) ? res : -res;
	return (res);
}
