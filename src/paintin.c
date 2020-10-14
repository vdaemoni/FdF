/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paintin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:52:41 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/02 17:43:57 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	positive(t_fdf *data)
{
	int err;
	int i;

	i = 0;
	err = data->dx / 2;
	while (i < data->dx)
	{
		data->x1 += data->incrx;
		err += data->dy;
		if (err > data->dx)
		{
			err -= data->dx;
			data->y1 += data->incry;
		}
		mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, data->colour);
		i++;
	}
}

void	negative(t_fdf *data)
{
	int err;
	int i;

	i = 0;
	err = data->dy / 2;
	while (i < data->dy)
	{
		data->y1 += data->incry;
		err += data->dx;
		if (err > data->dy)
		{
			err -= data->dy;
			data->x1 += data->incrx;
		}
		mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, data->colour);
		i++;
	}
}

void	pixels(t_fdf *data)
{
	data->incrx = (data->x2 > data->x1) ? 1 : -1;
	data->incry = (data->y2 > data->y1) ? 1 : -1;
	data->dx = abs(data->x2 - data->x1);
	data->dy = abs(data->y2 - data->y1);
	mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, data->colour);
	if (data->dx > data->dy)
		positive(data);
	else
		negative(data);
	mlx_pixel_put(data->mlx, data->win, data->x2, data->y2, data->colour);
}

void	draw_all_x(t_fdf *data)
{
	int i;

	i = 0;
	data->turn = 0;
	while (i < data->south)
	{
		while (data->turn < data->east[i] - 1)
		{
			data->x1 = data->view_x + (data->turn - i) * data->linesizex;
			data->y1 = data->view_y + (data->turn + i) * data->linesizey
				- (data->tab[i][data->turn] * data->z);
			data->x2 = data->view_x + ((data->turn + 1) - i) * data->linesizex;
			data->y2 = data->view_y + ((data->turn + 1) + i) * data->linesizey
				- (data->tab[i][data->turn + 1] * data->z);
			pixels(data);
			data->turn++;
		}
		i++;
		data->turn = 0;
	}
}

void	draw_all_y(t_fdf *data)
{
	int i;

	i = 0;
	data->turn = 0;
	while (i < data->south - 1)
	{
		while (data->turn < data->east[i])
		{
			data->x1 = data->view_x + (data->turn - i) * data->linesizex;
			data->y1 = data->view_y + (data->turn + i) * data->linesizey
				- (data->tab[i][data->turn] * data->z);
			data->x2 = data->view_x + ((data->turn)
				- (i + 1)) * data->linesizex;
			data->y2 = data->view_y
				+ ((data->turn) + (i + 1)) * data->linesizey
				- (data->tab[i + 1][data->turn] * data->z);
			pixels(data);
			data->turn++;
		}
		i++;
		data->turn = 0;
	}
}
