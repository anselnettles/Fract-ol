/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:57:05 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/25 17:32:22 by aviholai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "the_uncontrolled_element_of_life.h"
#define MAXCOUNT 30

float scale(int value, float n_min, float n_max, float o_max)
{
	float o_min;

	o_min = 0;

	return ((n_max - n_min) * (value - o_min) / (o_max - o_min) + n_min);
}

// 'Draw_fractal()' function can run either the Mandelbrot set fractal, made
// famous by Benoit Mandelbrot, working for IBM, in 1980, the Tricorn fractal,
// sometimes called the Mandelbar set, as introduced by
// W.D. Crowe, R.Hasson, P.J. Rippon and P.E.D. Strain-Clark, in 1989, as well
// as the Julia set fractal, named after the French mathematician Gaston Julia.

void	draw_fractal(t_fract *f)
{
	float	xscale, yscale, zx, zy, cx, tempx, cy;
	int		x;
	int		y;
	int		count;
	int		fractal_toggle;

	xscale = f->xside / WINDOW;
	yscale = f->yside / WINDOW;
	y = 1;
	if (f->request == TRICORN)
		fractal_toggle = -2;
	else
		fractal_toggle = 2;
	while (y <= WINDOW - 1)
	{
		x = 1;
		while (x <= WINDOW - 1)
		{
			cx = scale(x, -2, 2, WINDOW) * f->increment;
			cy = scale(y, -2, 2, WINDOW) * f->increment;
			if (f->request == JULIA)
			{
				zx = cx;
				zy = cy;
				cx = f->cursor_x;
				cy = f->cursor_y;
			}
			else
			{
				cx += f->cursor_x;
				cy += f->cursor_y;
				zx = 0;
				zy = 0;
			}
			count = 0;
			while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
			{
				tempx = zx * zx - zy * zy + cx;
				zy = fractal_toggle * zx * zy + cy;
				zx = tempx;
				count += 1;
			}
			mlx_pixel_put(f->mlx, f->win, x, y, ((count * 10) << 16 | (count * 8) << 7 | (count * 4) << 4));
			x++;
		}
		y++;
	}
}

// 'Launch_fractol()' initializes the 'MLX' library among its controls and
// appoints variables for the fractol sets.
// The mouse motion control, 'motion()', moves the graphical view and calls
// the 'draw_fractal()' function.

int	launch_fractol(t_fract *f)
{
	if (initialize_graphic(f) == -1)
		return (-1);
	f->left = (float)-1.75;
	f->top = (float)-0.25;
	f->xside = (float)0.25;
	f->yside = (float)0.45;
	f->increment = 1;
	if (mlx_hook(f->win, 6, 1L << 6, motion, (void *)f) == -1)
		return (-1);
	if (mlx_mouse_hook(f->win, mousepress, f) == -1)
		return (-1);
	if (mlx_key_hook(f->win, keypress, f) == -1)
		return (-1);
	mlx_loop(f->mlx);
	return (0);
}

// The Main() function checks the amount of arguments sent as parameter
// to the program and in the case of more than one, or if the argument is not
// a number from '1' to '3', prints the usage information.
// Moves on to run the fractal functions afterwards. In case a run time
// error occurs, gives an error message and returns '-1'.

int	main(int argc, char **argv)
{
	const char	*usage[5];
	t_fract		f;

	f.usage_lines = -1;
	if (argc == 2)
		f.request = ft_atoi(argv[1]);
	if (argc != 2 || (f.request != 1 && f.request != 2 && f.request != 3))
	{
		usage[0] = T_OG "Usage: " T_0 "./fractol " T_RED "<command number> \n";
		usage[1] = T_OG "Commands: " T_0;
		usage[2] = T_GREY "<" T_RED "1" T_GREY "> " T_0 "Mandelbrot | ";
		usage[3] = T_GREY "<" T_RED "2" T_GREY "> " T_0 "Julia | ";
		usage[4] = T_GREY "<" T_RED "3" T_GREY "> " T_0 "Tricorn | \n";
		while (++f.usage_lines <= 4)
			write(1, usage[f.usage_lines], ft_strlen(usage[f.usage_lines]));
		return (-1);
	}
	if (launch_fractol(&f) == -1)
	{
		usage[0] = T_RED "ERROR: " T_0 "Launch_fractol() error. Run failure.";
		while (++f.usage_lines <= 0)
			write (1, usage[f.usage_lines], ft_strlen(usage[f.usage_lines]));
		return (-1);
	}
	return (0);
}
