/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:51:25 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 04:24:51 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0 || (dest == '\0' && src == '\0' && size != 0))
		return (dest);
	if (dest <= src || dest >= (src + size))
	{
		while (i < size)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
	}
	else
		while (i < size)
		{
			((char*)dest)[size - i - 1] = ((char*)src)[size - i - 1];
			i++;
		}
	return (dest);
}
