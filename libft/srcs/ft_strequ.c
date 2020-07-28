/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:54:06 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 22:38:04 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i])
		{
			if ((s1[i + 1] == s2[i + 1]) && s1[i + 1] == '\0')
				return (1);
			i++;
		}
	}
	return (0);
}
