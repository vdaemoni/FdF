/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 18:34:32 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/15 20:22:24 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == 32)
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	nmb;
	int						sign;

	sign = 1;
	nmb = 0;
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if ((str[i] == '-' || str[i] == '+') &&
			(str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nmb = nmb * 10 + str[i++] - '0';
	if (nmb > 9223372036854775807 && sign == 1)
		return (-1);
	if (nmb > 9223372036854775807 && sign == -1)
		return (0);
	return (sign * nmb);
}
