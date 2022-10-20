/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:57:05 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/20 15:24:34 by aviholai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "the_uncontrolled_element_of_life.h"

// Cool story.

int	main(int argc, char **av)
{
	const char	*usage[5];
	int			i;

	if (argc != 2 || (f_ai(av[1]) != 1 && f_ai(av[1]) != 2 && f_ai(av[1]) != 3))
	{
		usage[0] = T_OG "Usage: " T_0 "./fractol " T_RED "<command number> \n";
		usage[1] = T_OG "Commands: " T_0;
		usage[2] = T_GREY "<" T_RED "1" T_GREY "> " T_0 "Mandelbrot | ";
		usage[3] = T_GREY "<" T_RED "2" T_GREY "> " T_0 "Julia | ";
		usage[4] = T_GREY "<" T_RED "3" T_GREY "> " T_0 "Whatever | \n";
		i = -1;
		while (++i <= 4)
			write(1, usage[i], ft_strlen(usage[i]));
		return (-1);
	}
//	DO FRACTOLS;
	return (0);
}
