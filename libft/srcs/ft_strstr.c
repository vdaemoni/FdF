/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:42:06 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/14 17:19:25 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *where, const char *what)
{
	int i;
	int j;
	int q;

	i = 0;
	j = 0;
	q = 0;
	if (ft_strlen(what) == 0)
		return ((char*)where);
	while (where[i])
	{
		q = i;
		while (what[j] == where[i])
		{
			if (what[j + 1] == '\0')
				return (&((char*)where)[q]);
			i++;
			j++;
		}
		i = q;
		j = 0;
		i++;
	}
	return (NULL);
}
