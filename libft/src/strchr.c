/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 17:24:05 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 12:25:02 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	if (c == 0)
		return ((char *)&(s[ft_strlen(s)]));
	return ((char *)ft_memchr(s, c, ft_strlen(s)));
}
