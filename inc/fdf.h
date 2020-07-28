/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <vdaemoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:32:45 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/07/20 20:32:45 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <io.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	int				z;
	int				south;
	int				*east;
	int				linesizex;
	int				linesizey;
	unsigned long	colour;
	int				**tab;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				dx;
	int				dy;
	int				incrx;
	int				incry;
	int				turn;
	int				view_x;
	int				view_y;
}					t_fdf;

int		key_pressed(int keycode, t_fdf *data);
void	draw_all_y(t_fdf *data);
void	draw_all_x(t_fdf *data);
void	draw(t_fdf *data);
int		tablen(char **tab);
void	ft_error(char *str);
void	work(int fd, t_fdf *data);
void	map_init(t_fdf *data);

#endif
