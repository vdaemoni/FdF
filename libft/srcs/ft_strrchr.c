/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:42:28 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/14 17:28:19 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *arr, int ch)
{
	size_t i;

	i = ft_strlen(arr);
	while (i > 0)
	{
		if (((char *)arr)[i] == ch)
			return (&((char *)arr)[i]);
		i--;
	}
	if (((char *)arr)[i] == ch)
		return (&((char *)arr)[i]);
	return (NULL);
}
