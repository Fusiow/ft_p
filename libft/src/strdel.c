/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 11:52:28 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/20 11:54:35 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	if (*as)
	{
		free(*as);
		*as = NULL;
	}
	as = NULL;
}
