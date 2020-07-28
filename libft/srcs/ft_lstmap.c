/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:53:36 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/16 18:32:59 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstfree(t_list *start)
{
	t_list *tmp;

	while (start)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *tmp;
	t_list *new_start;

	if (!lst || !f)
		return (NULL);
	if (!(tmp = f(lst)))
		return (NULL);
	new_start = tmp;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = f(lst)))
		{
			ft_lstfree(new_start);
			return (NULL);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_start);
}
