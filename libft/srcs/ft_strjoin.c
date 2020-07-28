/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:26:23 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/14 22:16:00 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	copy = (char *)malloc(sizeof(*copy) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (copy == NULL)
		return (NULL);
	while (*s1 != 0)
		copy[i++] = *s1++;
	while (*s2 != 0)
		copy[i++] = *s2++;
	copy[i] = '\0';
	return (copy);
}
