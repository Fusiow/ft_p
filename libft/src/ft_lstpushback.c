/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <rkharif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:44:00 by rkharif           #+#    #+#             */
/*   Updated: 2016/10/17 18:46:15 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list		*ft_lstpushback(t_list *lst, t_list *elem)
{
	t_list	*tmp;

	if (!lst)
		return (elem);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (lst);
}
