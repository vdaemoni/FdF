/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 14:49:01 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/08/03 20:48:00 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw(t_fdf *data)
{
	if (data->iso == 1)
	{
		draw_all_x(data);
		draw_all_y(data);
	}
	else if (data->iso == 0)
	{
		draw_non_iso_x(data);
		draw_non_iso_y(data);
	}
}

static void	ft_map(t_fdf *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->w, data->h, "FdF");
	draw(data);
	mlx_key_hook(data->win, key_pressed, data);
	mlx_loop(data->mlx);
}

void		map_init(t_fdf *data)
{
	data->h = 1080;
	data->w = 1920;
	data->z = 2;
	data->iso = 1;
	data->colour = 0x00FFFFFF;
	data->linesizex = 32;
	data->linesizey = 16;
	data->nonisizey = 32;
	data->view_x = 800;
	data->view_y = 400;
}

static void	count_south(int fd, t_fdf *data)
{
	char	*line;
	int		res;

	res = 0;
	line = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		res++;
		free(line);
	}
	data->south = res;
}

int			main(int argc, char **argv)
{
	t_fdf	data;
	int		fd;

	if (argc != 2)
		ft_error("usage: ./fdf [filename.fdf]");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Sorry! An error occured");
	map_init(&data);
	count_south(fd, &data);
	close(fd);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Sorry! An error occured");
	work(fd, &data);
	close(fd);
	ft_map(&data);
	complex_free(&data);
	return (0);
}
