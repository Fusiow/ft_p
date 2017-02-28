/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbinet <lbinet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:00:00 by lbinet            #+#    #+#             */
/*   Updated: 2015/01/21 15:33:33 by lbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*link;
	t_list	*new_lst;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	link = lst;
	new_lst = ft_lstnew(link->content, link->content_size);
	new_lst = f(new_lst);
	new_lst->next = NULL;
	new = new_lst;
	link = link->next;
	while (link)
	{
		new = ft_lstnew(link->content, link->content_size);
		new = f(new);
		ft_lstappend(&new_lst, new);
		link = link->next;
	}
	return (new_lst);
}
