/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkinzers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:52:40 by kkinzers          #+#    #+#             */
/*   Updated: 2019/03/24 16:52:45 by kkinzers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H
# define S_W 1200
# define S_H 600
# define COLOR "\x1b[35m"
# define COLOR_RESET "\x1b[0m"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*fract;
	char		*fract1;
	char		*data;
	int			bpp;
	int			sl;
	int			endian;
	int			color;
	double		nre;
	double		nim;
	double		oim;
	double		ore;
	double		c_re;
	double		c_im;
	double		z;
	double		mv_x;
	double		mv_y;
	double		julia_x;
	double		julia_y;
	double		startj_x;
	double		startj_y;
	int			stop;
	int			flag;
	int			sec_fr;
	int			space;
	int			iter;
}				t_mlx;

void			draw_mandelbrot(int x, int y, int i, t_mlx *a);
void			draw_julia(int x, int y, int i, t_mlx *a);
void			init_fractol(t_mlx *a);
void			init_keys(int key, t_mlx *a);
int				main_draw(t_mlx *a);
void			color_to_img(int x, int y, int i, t_mlx *a);
void			init(t_mlx *a);
int				deal_key(int key, t_mlx *a);
int				mouse_move(int x, int y, t_mlx *a);
int				mouse_hook(int button, int x, int y, t_mlx *a);
void			draw_circle(int x, int y, int i, t_mlx *a);
void			draw_ship(int x, int y, int i, t_mlx *a);
int				check_fract(t_mlx *a);
void			draw_spider(int x, int y, int i, t_mlx *a);
void			draw_thorn(int x, int y, int i, t_mlx *a);
int				new_window(t_mlx *a);
int				usage(int ac);
void			second_fract_key(int key, t_mlx *a);

#endif
