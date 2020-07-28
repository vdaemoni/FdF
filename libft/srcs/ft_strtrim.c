/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:37:39 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/18 14:41:07 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*copy;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
	{
		if (j < 0)
			return (ft_memalloc(1));
		j--;
	}
	copy = ft_memalloc(j - i + 2);
	if (copy == NULL)
		return (NULL);
	return (ft_strncpy(copy, &s[i], j - i + 1));
}
