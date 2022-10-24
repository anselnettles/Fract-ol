/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:57:05 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/24 17:45:27 by aviholai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "the_uncontrolled_element_of_life.h"
#define MAXCOUNT 30

// 'Mandelbrot()' function can run either the Mandelbrot set fractal, made
// famous by Benoit Mandelbrot, working for IBM, in 1980, as well as the
// Tricorn fractal, sometimes called the Mandelbar set, as introduced by
// W.D. Crowe, R.Hasson, P.J. Rippon and P.E.D. Strain-Clark, in 1989.

void	mandelbrot(t_fract *f)
{
	float	xscale, yscale, zx, zy, cx, tempx, cy;
	int		x;
	int		y;
	int		count;
	int		fractal_toggle;

	xscale = f->xside / WIDTH;
	yscale = f->yside / HEIGHT;
	y = 1;
	while (y <= HEIGHT - 1)
	{
		x = 1;
		while (x <= WIDTH - 1)
		{
			cx = (x * xscale + f->left) * f->increment;
			cy = (y * yscale + f->top) * f->increment2;
			zx = 0;
			zy = 0;
			count = 0;
			while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
			{
				if (f->request == 1)
					fractal_toggle = 2;
				else if (f->request == 3)
					fractal_toggle = -2;
				tempx = zx * zx - zy * zy + cx;
				zy = fractal_toggle * zx * zy + cy;
				zx = tempx;
				count += 1;
			}
			mlx_pixel_put(f->mlx, f->win, x, y, count * 10);
			x++;
		}
		y++;
	}
}

// 'Launch_fractol()' is a three-way fork that initializes the 'MLX' library
// and runs the requested fractal.
// Checks the parameter request from the user and moves on to the corresponding
// fractal function.

int	launch_fractol(t_fract *f)
{
	if (initialize_graphic(f) == -1)
		return (-1);
	if (f->request == MANDELBROT || f->request ==  TRICORN)
	{
		f->left = (float)-1.75;
		f->top = (float)-0.25;
		f->xside = (float)0.25;
		f->yside = (float)0.45;
		f->increment = 1;
		f->increment2 = 1;
		mandelbrot(f);
	}
	else if (f->request == JULIA)
	{
		//Julia.;
	}
	else
		return (-1);
	mlx_mouse_hook(f->win, mousepress, f);
	mlx_key_hook(f->win, keypress, f);
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
