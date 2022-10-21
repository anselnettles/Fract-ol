/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:57:05 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/21 19:42:04 by aviholai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "the_uncontrolled_element_of_life.h"
#define MAXCOUNT 30

void	mandelbrot(t_fract *f)
{
	float	xscale, yscale, zx, zy, cx, tempx, cy;
	int		x;
	int		y;
	int		count;

	xscale = f->xside / WIDTH;
	yscale = f->yside / HEIGHT;
	y = 1;
	while (y <= HEIGHT - 1)
	{
		x = 1;
		while (x <= WIDTH - 1)
		{
			cx = (x * xscale + f->left) * f->increment2;
			cy = (y * yscale + f->top) * f->increment;
			zx = 0;
			zy = 0;
			count = 0;
			while ((zx * zx + zy * zy < 4) && (count < MAXCOUNT))
			{
				tempx = zx * zx - zy * zy + cx;
				zy = 2 * zx * zy + cy;
				zx = tempx;
				count += 1;
			}
			mlx_pixel_put(f->mlx, f->win, x, y, count * 10);
			x++;
		}
		y++;
	}
}

// Checks the parameter request from the user and moves on to the corresponding
// fractal function.

int	launch_fractol(int request)
{
	t_fract	f;

	if (initialize_graphic(&f) == -1)
		return (-1);
	if (request == MANDELBROT)
	{
		f.left = (float)-1.75;
		f.top = (float)-0.25;
		f.xside = (float)0.25;
		f.yside = (float)0.45;
		f.increment = 1;
		f.increment2 = 1;
		mandelbrot(&f);
	}
	else if (request == JULIA)
	{
		//Julia.;
	}
	else if (request == TRICORN)
	{
		//Tricorn.;
	}
	else
		return (-1);
	mlx_mouse_hook(f.win, mousepress, &f);
	mlx_key_hook(f.win, keypress, &f);
	mlx_loop(f.mlx);
	return (0);
}

// The Main() function checks the amount of arguments sent as parameter
// to the program and in the case of more than one, or if the argument is not
// a number from '1' to '3', prints the usage information.
// Moves on to run the fractal functions afterwards. In case a run time
// error occurs, gives an error message and returns '-1'.

int	main(int argc, char **av)
{
	const char	*usage[5];
	int			i;

	i = -1;
	if (argc != 2 || (f_ai(av[1]) != 1 && f_ai(av[1]) != 2 && f_ai(av[1]) != 3))
	{
		usage[0] = T_OG "Usage: " T_0 "./fractol " T_RED "<command number> \n";
		usage[1] = T_OG "Commands: " T_0;
		usage[2] = T_GREY "<" T_RED "1" T_GREY "> " T_0 "Mandelbrot | ";
		usage[3] = T_GREY "<" T_RED "2" T_GREY "> " T_0 "Julia | ";
		usage[4] = T_GREY "<" T_RED "3" T_GREY "> " T_0 "Tricorn | \n";
		while (++i <= 4)
			write(1, usage[i], ft_strlen(usage[i]));
		return (-1);
	}
	if (launch_fractol(f_ai(av[1])) == -1)
	{
		usage[0] = T_RED "ERROR: " T_0 "Launch_fractol() error. Run failure.";
		while (++i <= 0)
			write (1, usage[i], ft_strlen(usage[i]));
		return (-1);
	}
	return (0);
}
