/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:30:06 by kkinzers          #+#    #+#             */
/*   Updated: 2019/06/07 22:30:08 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_thorn(int x, int y, int i, t_mlx *a)
{
	while (++y < S_H)
	{
		x = -1;
		while (++x < S_W)
		{
			i = -1;
			a->nre = 1.5 * (x - (S_W + 500) / 2) / (S_W * 0.5 * a->z) + a->mv_x;
			a->nim = (y - S_H / 2) / (S_H * 0.5 * a->z) + a->mv_y;
			a->c_re = 1;
			a->c_im = 1;
			while (++i < a->iter)
			{
				a->ore = a->nre;
				a->oim = a->nim;
				a->nre = a->ore / cos(a->oim) + a->c_re;
				a->nim = a->oim / cos(a->ore) + a->c_im;
				if (a->nre * a->nre + a->nim * a->nim > 800)
				{
					color_to_img(x, y, i, a);
					break ;
				}
			}
		}
	}
}

void		color_to_img(int x, int y, int i, t_mlx *a)
{
	double	t;
	int		q;

	t = (double)i / a->iter;
	q = x * a->bpp / 8 + y * a->sl;
	if (a->color == 1)
	{
		a->data[q] = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		a->data[q + 1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		a->data[q + 2] = (int)(9 * (1 - t) * t * t * t * 255);
	}
	if (a->color == 2)
	{
		a->data[q] = (int)(8.5 * (1 - t) * t * t * t * 255);
		a->data[q + 1] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		a->data[q + 2] = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	if (a->color == 3)
	{
		a->data[q] = (int)(8.5 * (1 - t) * t * t * t * 255);
		a->data[q + 1] = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		a->data[q + 2] = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	}
}

int			check_fract(t_mlx *a)
{
	if (ft_strcmp(a->fract, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(a->fract, "Julia") == 0)
		return (1);
	else if (ft_strcmp(a->fract, "Circle") == 0)
		return (1);
	else if (ft_strcmp(a->fract, "Ship") == 0)
		return (1);
	else if (ft_strcmp(a->fract, "Spider") == 0)
		return (1);
	else if (ft_strcmp(a->fract, "Thorn") == 0)
		return (1);
	else
		return (0);
}

void		init_fractol(t_mlx *a)
{
	if (ft_strcmp(a->fract, "Mandelbrot") == 0)
		draw_mandelbrot(0, -1, 0, a);
	else if (ft_strcmp(a->fract, "Julia") == 0)
		draw_julia(0, -1, 0, a);
	else if (ft_strcmp(a->fract, "Circle") == 0)
		draw_circle(0, -1, 0, a);
	else if (ft_strcmp(a->fract, "Ship") == 0)
		draw_ship(0, -1, 0, a);
	else if (ft_strcmp(a->fract, "Spider") == 0)
		draw_spider(0, -1, 0, a);
	else if (ft_strcmp(a->fract, "Thorn") == 0)
		draw_thorn(0, -1, 0, a);
}

void		init(t_mlx *a)
{
	a->z = 1;
	a->stop = 0;
	a->flag = 0;
	a->mv_x = 0;
	a->mv_y = 0;
	a->color = 1;
	a->startj_x = 0;
	a->startj_y = 0;
	a->iter = 150;
	init_fractol(a);
}
