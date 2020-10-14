/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noniso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:44:26 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/03 20:32:26 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	connecty(t_fdf *data)
{
	int i;

	i = 0;
	data->incry = data->y2 - data->y1;
	while (i < data->incry)
	{
		mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, data->colour);
		data->y1++;
		i++;
	}
}

static void	connectx(t_fdf *data)
{
	int i;

	i = 0;
	data->incrx = data->x2 - data->x1;
	while (i < data->incrx)
	{
		mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, data->colour);
		data->x1++;
		i++;
	}
}

void		draw_non_iso_y(t_fdf *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->x1 = data->view_x;
	data->x2 = data->x1;
	while (i <= data->east[1])
	{
		data->y1 = data->view_y;
		data->y2 = data->y1 + data->nonisizey;
		while (j < data->south - 1)
		{
			connecty(data);
			data->y1 = data->y2;
			data->y2 = data->y1 + data->nonisizey;
			j++;
		}
		i++;
		j = 0;
		data->x1 = data->x2;
		data->x2 = data->x1 + data->linesizex;
	}
}

void		draw_non_iso_x(t_fdf *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->y1 = data->view_y;
	data->y2 = data->y1 + data->nonisizey;
	while (i < data->south)
	{
		data->x1 = data->view_x;
		data->x2 = data->x1 + data->linesizex;
		while (j < data->east[i] - 1)
		{
			connectx(data);
			data->x1 = data->x2;
			data->x2 = data->x1 + data->linesizex;
			j++;
		}
		i++;
		j = 0;
		data->y1 = data->y2;
		data->y2 = data->y1 + data->nonisizey;
	}
	mlx_pixel_put(data->mlx, data->win, data->x1, data->y1
		- data->nonisizey, data->colour);
}
