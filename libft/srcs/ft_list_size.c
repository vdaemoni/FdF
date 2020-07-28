/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:09:22 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/16 15:15:36 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size(t_list *begin_list)
{
	t_list	*ptr;
	int		k;

	k = 0;
	if (begin_list)
	{
		ptr = begin_list;
		while (ptr != NULL)
		{
			ptr = ptr->next;
			k++;
		}
	}
	return (k);
}
