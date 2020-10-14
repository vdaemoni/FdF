/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:46:19 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/03 20:05:01 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	complex_free(t_fdf *data)
{
	int i;

	i = 0;
	free(data->east);
	while (i < data->south)
	{
		free(data->tab[i]);
		i++;
	}
	free(data->tab);
}

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
