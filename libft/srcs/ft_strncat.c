/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:39:00 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/12 04:59:59 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *dop, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (dop[j] != '\0')
	{
		if (j == size)
		{
			dest[i] = '\0';
			return (dest);
		}
		dest[i] = dop[j];
		i++;
		j++;
	}
	dest[i] = dop[j];
	return (dest);
}
