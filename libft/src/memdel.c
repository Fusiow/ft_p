/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:40:20 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 14:24:42 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		ft_memdel(void **ap)
{
	if (ap == NULL)
		return ;
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
