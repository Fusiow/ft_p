/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:51:24 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/13 15:28:49 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	if (str)
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
