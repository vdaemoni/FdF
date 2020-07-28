/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:53:45 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/14 17:54:02 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *dop, size_t size)
{
	size_t i;
	size_t j;
	size_t l;

	i = 0;
	j = 0;
	l = 0;
	while (dest[i] != '\0')
		i++;
	while (dop[l] != '\0')
		l++;
	if (size <= i)
		l = l + size;
	else
		l = l + i;
	while (dop[j] != '\0' && i + 1 < size)
	{
		dest[i] = dop[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (l);
}
