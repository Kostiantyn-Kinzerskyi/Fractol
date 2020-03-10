/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:52:18 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/24 16:52:20 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			close_x(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int			main_draw(t_mlx *a)
{
	mlx_destroy_image(a->mlx, a->img);
	a->img = mlx_new_image(a->mlx, S_W, S_H);
	a->data = mlx_get_data_addr(a->img, &a->bpp, &a->sl, &a->endian);
	init_fractol(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	return (0);
}

int			new_window(t_mlx *a)
{
	if (!check_fract(a))
	{
		ft_putendl("wrong name");
		ft_putendl("name: Mandelbrot, Julia, Circle, Ship, Spider, Thorn");
		return (0);
	}
	if (ft_strcmp(a->fract, "Julia") == 0 || ft_strcmp(a->fract, "Circle") == 0)
	{
		if (a->space == 0)
			ft_putendl(COLOR " Freeze picture: Space" COLOR_RESET);
		a->space++;
	}
	a->mlx = mlx_init();
	a->win = mlx_new_window(a->mlx, S_W, S_H, "42");
	a->img = mlx_new_image(a->mlx, S_W, S_H);
	a->data = mlx_get_data_addr(a->img, &a->bpp, &a->sl, &a->endian);
	init(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	mlx_hook(a->win, 4, 4, mouse_hook, a);
	mlx_hook(a->win, 2, 2, deal_key, a);
	mlx_hook(a->win, 6, 6, mouse_move, a);
	mlx_hook(a->win, 17, 1L << 17, close_x, a);
	mlx_loop(a->mlx);
	return (0);
}

int			usage(int ac)
{
	if (ac > 3)
	{
		ft_putendl("Too much options");
		return (0);
	}
	if (ac < 2)
	{
		ft_putendl("usage: ./fractol name");
		ft_putendl("name: Mandelbrot, Julia, Circle, Ship, Spider, Thorn");
		return (0);
	}
	ft_putendl(COLOR " Move: arrows" COLOR_RESET);
	ft_putendl(COLOR " Zoom: mouse wheel" COLOR_RESET);
	ft_putendl(COLOR " Reset: Q" COLOR_RESET);
	ft_putendl(COLOR " Change color: 1 2 3" COLOR_RESET);
	ft_putendl(COLOR " Iterations: < >" COLOR_RESET);
	if (ac == 3)
		ft_putendl(COLOR " Open Second fractal: Z" COLOR_RESET);
	return (1);
}

int			main(int argc, char **argv)
{
	t_mlx	a;

	a.space = 0;
	a.sec_fr = argc;
	if (!argv[1])
	{
		usage(argc);
		return (0);
	}
	a.fract = argv[1];
	if (check_fract(&a))
		if (!usage(argc))
			return (0);
	a.fract = argv[1];
	if (argc == 3)
		a.fract1 = argv[2];
	new_window(&a);
	return (0);
}
