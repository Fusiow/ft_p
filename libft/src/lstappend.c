/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstappend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:02:41 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 15:04:28 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*link;

	if (alst == NULL || *alst == NULL || new == NULL)
		return ;
	link = *alst;
	while (link->next)
		link = link->next;
	link->next = new;
	new->next = NULL;
}
