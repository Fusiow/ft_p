/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:58:24 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/19 15:00:00 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	if (n == 0 || s == NULL)
		return ;
	ft_memset(s, 0, n);
}
