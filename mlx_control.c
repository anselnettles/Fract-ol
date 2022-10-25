/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:21:54 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/25 17:28:39 by aviholai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "the_uncontrolled_element_of_life.h"
#include <stdio.h>

void	write_strings(t_fract *f)
{
	mlx_string_put(f->mlx, f->win, 30, 20, NETTLE,
		"Fract'ol |  \\ˈfrakt(a)l\\ | \"broken\", \"fractured\".");
	mlx_string_put(f->mlx, f->win, 60, 45, DAWN,
		"A fractal is a rough or fragment geometric shape, split into parts,");
	mlx_string_put(f->mlx, f->win, 60, 65, DAWN,
		"each of which is a reduced-size copy of the whole.");
	mlx_string_put(f->mlx, f->win, 60, WINDOW - 160, GREY,
		"| Move mouse to adjust the fractal | Scroll mouse to zoom. |");
	mlx_string_put(f->mlx, f->win, WINDOW - 440, WINDOW - 65, NETTLE,
		"Ansel Nettles | github.com/anselnettles");
	mlx_string_put(f->mlx, f->win, WINDOW - 440, WINDOW - 45, DAWN,
		"\" C o d e - ' n - S w o r d \"");
}

int	mousepress(int key, int x, int y, void *param)
{
	t_fract *f;

	f = (t_fract *)param;
	if (x < 0 || y < 0 || x > WINDOW || y > WINDOW)
		return (0);
	if (key == ZOOM_IN)
		f->increment /= (float)0.1;
	if (key == ZOOM_OUT)
		f->increment *= (float)0.1;
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f);
	write_strings(f);
	return (1);
}

int	keypress(int key, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	if (key)
	{
		if (key == ESC)
		{
			mlx_destroy_window(f->mlx, f->win);
			exit (0);
		}
	}
	return (0);
}

int motion(int x, int y, void *param)
{
	t_fract *f;

	f = (t_fract *)param;

	f->cursor_x = scale(x, -2, 2, WINDOW);
	f->cursor_y = scale(y, -2, 2, WINDOW);
	mlx_clear_window(f->mlx, f->win);
	draw_fractal(f);
	write_strings(f);
	return (0);
}

int	initialize_graphic(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WINDOW, WINDOW,
			"Fract'ol | github.com/anselnettles");
	write_strings(f);
	return (0);
}
