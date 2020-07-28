/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:35:25 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 22:31:53 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	if (s && f)
	{
		j = ft_strlen(s);
		copy = ft_memalloc(j + 1);
		if (copy == NULL)
			return (NULL);
		copy = ft_strncpy(copy, s, j);
		while (s[i])
		{
			copy[i] = (*f)(s[i]);
			i++;
		}
		return (copy);
	}
	return (NULL);
}
