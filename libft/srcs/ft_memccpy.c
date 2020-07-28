/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:24:36 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 20:49:58 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			return (&dest[i + 1]);
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (NULL);
}
