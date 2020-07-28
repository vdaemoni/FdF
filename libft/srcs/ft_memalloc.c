/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:51:17 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/10 13:35:42 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *copy;

	copy = malloc(size);
	if (copy == NULL)
		return (NULL);
	else
		ft_memset(copy, '\0', size);
	return (copy);
}
