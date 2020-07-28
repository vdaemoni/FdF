/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 17:48:23 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/07/24 17:48:23 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		tablen(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	ft_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}
