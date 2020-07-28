/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:57:02 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/13 16:30:38 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *where, const char *what, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	q;

	i = 0;
	if (what[i] == 0)
		return ((char *)where);
	while (where[i])
	{
		j = 0;
		q = i;
		while (what[j] == where[i] && i < size)
		{
			if (size == i)
				return (NULL);
			if (what[j + 1] == '\0')
				return (&((char*)where)[q]);
			i++;
			j++;
		}
		i = q;
		i++;
	}
	return (NULL);
}
