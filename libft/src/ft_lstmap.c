/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:35:09 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/13 16:26:23 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*newlist;
	t_list		*tmp;
	t_list		*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = f(lst);
	if ((newlist = ft_lstnew(tmp2->content, tmp2->content_size)))
	{
		tmp = newlist;
		lst = lst->next;
		while (lst)
		{
			tmp2 = f(lst);
			if (!(tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)))
				return (NULL);
			lst = lst->next;
			tmp = tmp->next;
		}
	}
	return (newlist);
}
