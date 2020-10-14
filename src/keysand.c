/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keysand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:47:15 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/03 20:52:05 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	more_view(int keycode, t_fdf *data)
{
	if (keycode == 126)
	{
		data->view_y -= 100;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 125)
	{
		data->view_y += 100;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 123)
	{
		data->view_x -= 100;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 124)
	{
		data->view_x += 100;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	return (0);
}

static int	colours(int keycode, t_fdf *data)
{
	if (keycode == 11)
	{
		data->colour = 0x0000FF;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 15)
	{
		data->colour = 0xFF0000;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 5)
	{
		data->colour = 0x00FF00;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	return (0);
}

static int	zoom(int keycode, t_fdf *data)
{
	if (keycode == 75)
	{
		if (data->linesizey > 1)
		{
			data->linesizex = data->linesizex / 2;
			data->linesizey = data->linesizey / 2;
			data->nonisizey = data->nonisizey / 2;
		}
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 67)
	{
		data->linesizex = data->linesizex * 2;
		data->linesizey = data->linesizey * 2;
		data->nonisizey = data->nonisizey * 2;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	return (0);
}

static int	iso(int keycode, t_fdf *data)
{
	if (keycode == 48 && data->iso == 1)
	{
		data->iso = 0;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	else if (keycode == 48 && data->iso == 0)
	{
		data->iso = 1;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	return (0);
}

int			key_pressed(int keycode, t_fdf *data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		data->z++;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 78)
	{
		data->z--;
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	if (keycode == 49)
	{
		map_init(data);
		mlx_clear_window(data->mlx, data->win);
		draw(data);
	}
	more_view(keycode, data);
	colours(keycode, data);
	zoom(keycode, data);
	iso(keycode, data);
	return (0);
}
