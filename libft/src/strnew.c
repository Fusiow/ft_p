/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:44:50 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/20 11:47:39 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*s;

	s = (char *)malloc(size * sizeof(char));
	if (s)
		ft_bzero(s, size * sizeof(char));
	return (s);
}
