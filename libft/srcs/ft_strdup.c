/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:42:13 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 02:43:41 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;

	copy = (char *)ft_memalloc(ft_strlen(src) + 1);
	if (copy == NULL)
		return (NULL);
	ft_strcpy(copy, src);
	return (copy);
}
