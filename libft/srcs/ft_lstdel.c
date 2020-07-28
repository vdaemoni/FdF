/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:23:33 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/16 15:42:06 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*list;
	t_list	*nextlist;

	if (alst && *alst && del)
	{
		list = *alst;
		while (list)
		{
			nextlist = list->next;
			del(list->content, list->content_size);
			free(list);
			list = nextlist;
		}
		*alst = NULL;
	}
}
