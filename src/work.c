/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:53:56 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/03 20:29:58 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	false_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
			if (tab[i][j] == '-')
			{
				j++;
				while (tab[i][j] != 0)
				{
					if (tab[i][j] < '0' || tab[i][j] > '9')
						return (1);
					j++;
				}
			}
			else if (tab[i][j] >= '0' && tab[i][j] <= '9')
				j++;
			else
				return (1);
		i++;
	}
	return (0);
}

static int	determine_east(char *line, t_fdf *data, int i)
{
	int		j;
	char	**tab;

	j = 0;
	tab = ft_strsplit(line, ' ');
	if (false_tab(tab) == 1)
		return (-1);
	data->east[i] = tablen(tab);
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (1);
}

static void	printo(t_fdf data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data.south)
	{
		ft_putstr("Line ");
		ft_putnbr(i + 1);
		ft_putstr(": ");
		while (j < data.east[i])
		{
			ft_putnbr(data.tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

static int	*coordinate(char *line, int eastmax)
{
	char	**tab;
	int		i;
	int		*oneline;

	i = 0;
	tab = ft_strsplit(line, ' ');
	if (!(oneline = (int *)malloc(sizeof(int) * eastmax)))
		return (NULL);
	while (tab[i] && (i < eastmax))
	{
		oneline[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (oneline);
}

void		work(int fd, t_fdf *data)
{
	char	*line;
	int		i;

	if (!(data->tab = (int **)malloc(sizeof(int *) * data->south)))
		ft_error("Sorry! An error occured");
	if (!(data->east = (int *)malloc(sizeof(int) * data->south)))
		ft_error("Sorry! An error occured");
	line = NULL;
	i = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((determine_east(line, data, i)) == -1)
			ft_error("Sorry! An error occured");
		if (i != 0)
			if (data->east[i] != data->east[i - 1])
				ft_error("Sorry! An error occured");
		if ((data->tab[i] = coordinate(line, data->east[0])) == NULL)
			ft_error("Sorry! An error occured");
		i++;
		free(line);
	}
	printo(*data);
}
