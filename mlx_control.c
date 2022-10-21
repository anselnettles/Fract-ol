/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:21:54 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/21 17:57:53 by aviholai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "the_uncontrolled_element_of_life.h"
#include <stdio.h>

int	mousepress(int key, int x, int y, void *param)
{
	t_fract *f;

	f = (t_fract *)param;
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (0);
	if (key == ZOOM_IN)
	{
		printf("in. %f. ", f->increment);
		f->increment -= (float)0.05;
		//f->xside += (float)0.25;
		//f->yside += (float)0.45;
		//f->left -= (float)1.75;
		//f->top -= (float)0.25;
	}
	if (key == ZOOM_OUT)
	{
		printf("out. %f. ", f->increment);
		f->increment += (float)0.05;
		//f->xside -= (float)0.25;
		//f->yside -= (float)0.45;
	}
	mlx_clear_window(f->mlx, f->win);
	mandelbrot(f);
	return (1);
}

int	keypress(int key, void *param)
{
	t_fract	*f;

	f = (t_fract *)param;
	if (key)
	{
		if (key == TAB)
		{
			//Switch to another fractal.
		}
		if (key == ESC)
		{
			mlx_destroy_window(f->mlx, f->win);
			exit (0);
		}
	}
	return (0);
}

int	initialize_graphic(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT,
			"Fract'ol | github.com/anselnettles");
	mlx_string_put(f->mlx, f->win, 30, 20, NETTLE,
		"Fract'ol |  \\ˈfrakt(a)l\\ | god dang fractals");
	mlx_string_put(f->mlx, f->win, WIDTH - 440, HEIGHT - 65, NETTLE,
		"Ansel Nettles | github.com/anselnettles");
	mlx_string_put(f->mlx, f->win, WIDTH - 440, HEIGHT - 45, DAWN,
		"\" C o d e - ' n - S w o r d \"");
	return (0);
}
