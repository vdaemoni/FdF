/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:02:42 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 22:40:38 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *copy;

	if (!s)
		return (NULL);
	copy = ft_memalloc(len + 1);
	if (copy == NULL)
		return (NULL);
	return (ft_memcpy(copy, &s[start], len));
}
