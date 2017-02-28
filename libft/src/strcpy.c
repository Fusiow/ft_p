/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:25:18 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 12:25:35 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	if (src == NULL || dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, ft_strlen(src));
	dst[ft_strlen(src)] = '\0';
	return (dst);
}
