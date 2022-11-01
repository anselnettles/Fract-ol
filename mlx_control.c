/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:21:54 by aviholai          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/31 14:34:00 by aviholai         ###   ########.fr       */
=======
/*   Updated: 2022/11/01 13:28:00 by aviholai         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "the_uncontrolled_element_of_life.h"
#include <stdio.h>

// User interface string functions that are applied on top of each draw sequence

void	write_strings(t_fract *f)
{
	mlx_string_put(f->mlx, f->win, 30, 20, NETTLE,
		"Fract'ol |  \\ˈfrakt(a)l\\ | \"broken\", \"fractured\".");
	mlx_string_put(f->mlx, f->win, 60, 45, DAWN,
		"A fractal is a rough or fragment geometric shape, split into parts,");
	mlx_string_put(f->mlx, f->win, 60, 65, DAWN,
		"each of which is a reduced-size copy of the whole.");
	mlx_string_put(f->mlx, f->win, 60, WINDOW - 160, GREY,
		"| Move mouse: Adjust fractal. | Scroll wheel: Zoom. | ESC: Quit. |");
	mlx_string_put(f->mlx, f->win, WINDOW - 440, WINDOW - 65, NETTLE,
		"Ansel Nettles | github.com/anselnettles");
	mlx_string_put(f->mlx, f->win, WINDOW - 440, WINDOW - 45, DAWN,
		"\" C o d e - ' n - S w o r d \"");
}

// Mouse button inputs for various control.

int	mousepress(int key, int x, int y, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	if (x < 0 || y < 0 || x > WINDOW || y > WINDOW)
		return (0);
	if (key == MAC_ZOOM_IN || key == LINUX_ZOOM_IN)
		f->increment *= (float)0.5;
	if (key == MAC_ZOOM_OUT || key == LINUX_ZOOM_OUT)
		f->increment /= (float)0.5;
	if ((key == MAC_CLICK || key == LINUX_CLICK) && f->request <= JULIA)
		f->request++;
	else if ((key == MAC_CLICK || key == LINUX_CLICK) && f->request == TRICORN)
		f->request = MANDELBROT;
	//if ((key == MAC_RIGHT_CLICK || key == LINUX_RIGHT_CLICK))
	//		f->right_click = TRUE;
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f);
	write_strings(f);
	return (0);
}

// ESC key for quitting the executable.

int	keypress(int key, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	if (key == MAC_ESC || key == LINUX_ESC)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit (0);
	}
	return (0);
}

//	Mouse motion input is set here. 'Mouse_x' and 'mouse_y' variables are
//	imperative for fractal Julia to perform in movement.

int	motion(int x, int y, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	//if (f->right_click != TRUE)
	//{
		f->mouse_x = scale(x, -2, 2, WINDOW);
		f->mouse_y = scale(y, -2, 2, WINDOW);
	//}
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f);
	write_strings(f);
	return (0);
}

// 'Initialize()' runs the MLX library tools and executes the graphic window.
// Variables for the fractal configuration are set here.

int	initialize(t_fract *f)
{
	f->mlx = mlx_init();
	if (!(f->mlx))
		return (-1);
	f->win = mlx_new_window(f->mlx, WINDOW, WINDOW,
			"Fract'ol | github.com/anselnettles");
	if (!(f->win))
		return (-1);
	f->increment = 1;
	f->right_click = FALSE;
	draw_fractal(f);
	write_strings(f);
	return (0);
}
