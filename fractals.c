/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:50:19 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/29 20:50:20 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_julia(int x, int y, int i, t_mlx *a)
{
	while (++y < S_H)
	{
		x = -1;
		while (++x < S_W)
		{
			i = -1;
			a->c_re = -0.70176 + (a->julia_x / 2000);
			a->c_im = -0.3842 + (a->julia_y / 2000);
			a->nre = 1.5 * (x - S_W / 2) / (S_W * 0.5 * a->z) + a->mv_x;
			a->nim = (y - S_H / 2) / (S_H * 0.5 * a->z) + a->mv_y;
			while (++i < a->iter)
			{
				a->ore = a->nre;
				a->oim = a->nim;
				a->nre = a->ore * a->ore - a->oim * a->oim + a->c_re;
				a->nim = 2 * a->ore * a->oim + a->c_im;
				if (a->nre * a->nre + a->nim * a->nim > 4)
				{
					color_to_img(x, y, i, a);
					break ;
				}
			}
		}
	}
}

void		draw_mandelbrot(int x, int y, int i, t_mlx *a)
{
	while (++y < S_H)
	{
		x = -1;
		while (++x < S_W)
		{
			i = -1;
			a->c_re = 2 * (x - (S_W + 500) / 2) / (S_W * 0.5 * a->z) + a->mv_x;
			a->c_im = (y - S_H / 2) / (S_H * 0.5 * a->z) + a->mv_y;
			a->nim = 0;
			a->nre = 0;
			while (++i < a->iter)
			{
				a->ore = a->nre;
				a->oim = a->nim;
				a->nre = a->ore * a->ore - a->oim * a->oim + a->c_re;
				a->nim = 2 * a->ore * a->oim + a->c_im;
				if (a->nre * a->nre + a->nim * a->nim > 4)
				{
					color_to_img(x, y, i, a);
					break ;
				}
			}
		}
	}
}

void		draw_circle(int x, int y, int i, t_mlx *a)
{
	while (++y < S_H)
	{
		x = -1;
		while (++x < S_W)
		{
			a->c_re = 2 * (x - (S_W + 500) / 2) / (S_W * 0.5 * a->z) + a->mv_x;
			a->c_im = (y - S_H / 2) / (S_H * 0.5 * a->z) + a->mv_y;
			i = (int)(a->c_re * a->c_re + a->c_im *
				a->c_im + (a->julia_x / 2) + (a->julia_y / 2)) % 255;
			color_to_img(x, y, i, a);
		}
	}
}

void		draw_ship(int x, int y, int i, t_mlx *a)
{
	while (++y < S_H)
	{
		x = -1;
		while (++x < S_W)
		{
			i = -1;
			a->c_re = 2 * (x - (S_W + 200) / 2) /
			(S_W * 0.5 * a->z) + a->mv_x;
			a->c_im = (y - (S_H + 250) / 2) /
			(S_H * 0.5 * a->z) + a->mv_y;
			a->nim = a->c_re;
			a->nre = a->c_im;
			while (++i < a->iter)
			{
				a->ore = a->nim * a->nim - a->nre * a->nre + a->c_re;
				a->nre = fabs(2 * a->nim * a->nre) + a->c_im;
				a->nim = fabs(a->ore);
				if (a->nre * a->nre + a->nim * a->nim > 4)
				{
					color_to_img(x, y, i, a);
					break ;
				}
			}
		}
	}
}

void		draw_spider(int x, int y, int i, t_mlx *a)
{
	while (++y < S_H)
	{
		x = -1;
		while (++x < S_W)
		{
			i = -1;
			a->nre = 1.5 * (x - (S_W + 500) / 2) / (S_W * 0.5 * a->z) + a->mv_x;
			a->nim = (y - S_H / 2) / (S_H * 0.5 * a->z) + a->mv_y;
			a->c_re = a->nre;
			a->c_im = a->nim;
			while (++i < a->iter)
			{
				a->ore = a->nre;
				a->oim = a->nim;
				a->nre = a->ore * a->ore - a->oim * a->oim + a->c_re;
				a->nim = 2 * a->ore * a->oim + a->c_im;
				a->c_re = a->c_re / 2 + a->nre;
				a->c_im = a->c_im / 2 + a->nim;
				if (a->nre * a->nre + a->nim * a->nim > 4)
					color_to_img(x, y, i, a);
				if (a->nre * a->nre + a->nim * a->nim > 4)
					break ;
			}
		}
	}
}
