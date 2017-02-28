/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:40:23 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 14:56:01 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;
	t_list	*tmp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	link = *alst;
	while (link)
	{
		del(link->content, link->content_size);
		tmp = link;
		link = link->next;
		free(tmp);
		tmp = NULL;
	}
	*alst = NULL;
}
