/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:04:43 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/29 21:04:50 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			deal_key(int key, t_mlx *a)
{
	if (key == 53)
		exit(0);
	if (key == 124)
		a->mv_x += 0.1 / a->z;
	if (key == 123)
		a->mv_x -= 0.1 / a->z;
	if (key == 126)
		a->mv_y -= 0.1 / a->z;
	if (key == 125)
		a->mv_y += 0.1 / a->z;
	if (key == 18)
		a->color = 1;
	if (key == 19)
		a->color = 2;
	if (key == 20)
		a->color = 3;
	if (key == 43 && a->iter > 5)
		a->iter -= 5;
	if (key == 47)
		a->iter += 5;
	second_fract_key(key, a);
	init_keys(key, a);
	return (0);
}

void		init_keys(int key, t_mlx *a)
{
	if (key == 12)
	{
		a->mv_x = 0;
		a->mv_y = 0;
		a->z = 1;
		a->julia_x = 1;
		a->julia_y = 1;
		a->stop = 0;
		a->flag++;
		a->iter = 150;
		a->color = 1;
	}
	if (key == 49)
	{
		if (a->stop == 0)
			a->stop = 1;
		else
		{
			a->stop = 0;
			a->flag++;
		}
	}
	main_draw(a);
}

void		second_fract_key(int key, t_mlx *a)
{
	t_mlx	b;

	if (key == 6 && a->sec_fr == 3)
	{
		a->sec_fr--;
		b = *a;
		b.fract = a->fract1;
		init_fractol(&b);
		new_window(&b);
	}
}

int			mouse_move(int x, int y, t_mlx *a)
{
	if (a->stop == 0 && a->startj_x == 0 && a->startj_y == 0)
	{
		a->startj_x = x;
		a->startj_y = y;
	}
	if (a->flag == 1)
	{
		a->startj_x += (x - a->startj_x - a->julia_x);
		a->startj_y += (y - a->startj_y - a->julia_y);
		a->flag--;
	}
	if (a->stop == 0)
	{
		a->julia_x = (x - a->startj_x);
		a->julia_y = (y - a->startj_y);
		mlx_loop_hook(a->mlx, main_draw, a);
	}
	return (0);
}

int			mouse_hook(int button, int x, int y, t_mlx *a)
{
	double	j;
	double	i;

	j = 0;
	i = 0;
	if (button == 5)
	{
		a->z /= 1.03;
		j = ((S_W / 2 - (double)x) /
			((S_W + fabs(S_W / 2 - (double)x)) * 3)) / a->z;
		i = ((S_H / 2 - (double)y) /
			((S_H + fabs(S_H / 2 - (double)y)) * 8)) / a->z;
	}
	if (button == 4)
	{
		a->z *= 1.03;
		j = (-(S_W / 2 - (double)x) /
			((S_W + fabs(S_W / 2 - (double)x)) * 3)) / a->z;
		i = (-(S_H / 2 - (double)y) /
			((S_H + fabs(S_H / 2 - (double)y)) * 8)) / a->z;
	}
	a->mv_x += j;
	a->mv_y += i;
	mlx_loop_hook(a->mlx, main_draw, a);
	return (0);
}
