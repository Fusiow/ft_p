/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:25:34 by rkharif           #+#    #+#             */
/*   Updated: 2016/02/23 17:37:12 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*sp1;

	if ((sp1 = malloc(ft_strlen(s1) + 1)))
	{
		ft_memcpy(sp1, s1, ft_strlen(s1));
		sp1[ft_strlen(s1)] = '\0';
	}
	return (sp1);
}
