/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_uncontrolled_element_of_life.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:59:27 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/20 18:36:37 by aviholai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	``Beautiful, damn hard, increasingly useful. That's fractals.``
//	— Benoit Mandelbrot

#ifndef THE_UNCONTROLLED_ELEMENT_OF_LIFE_H
# define THE_UNCONTROLLED_ELEMENT_OF_LIFE_H

# include <unistd.h>			// UNIX Standard library. ('write()')
# include <stdlib.h>			// Standard library. ('size_t', 'NULL', 'exit')
//# include <string.h>			// String library.
//# include <math.h>			// Math library. 
# include "mlx.h"				// MiniLibraryX graphics library.

// Terminal definitions.
# define MANDELBROT 1			// Reference to running Mandelbrot.
# define JULIA 2				// Reference to running Julia.
# define TRICORN 3				// Reference to running Tricorn.

// Graphic window definitions.
# define WIDTH 1080				// Window resolution width
# define HEIGHT 920				// Window resolution height

// Mac keyboard control definitions.
# define TAB 48					// Mac TAB key.
# define ESC 53					// Mac ESC key.

// Terminal output colors.
# define T_GREY "\033[0;37m"	// Grey terminal color.
# define T_OG "\033[1;33m"		// Orange bold terminal color.
# define T_YELL "\033[0;33m"	// Yellow terminal color.
# define T_RED "\033[0;31m"		// Red terminal color.
# define T_0 "\033[0m"			// Default terminal color.

// Graphic window colors.
# define RED 0xCC0000			// Graphic red color.
# define NETTLE 0xAAD4B5		// Graphic "nettles" shade.
# define NIGHT 0x152f37			// Graphic "nightly" shade.
# define DAWN 0x2b6173			// Graphic "twilit" shade.
# define ORANGE 0xE7C9B1		// Graphic orange color.
# define WHITE 0xdbdbdb			// Not-quite-white white shade.
# define GREY 0x828282			// Graphic grey color.

typedef struct s_fract {
	void	*mlx;
	void	*win;
}	t_fract;

int		main(int argc, char **argv);	// Main function.
int		launch_fractol(int request);	// Runs the request to graphic view.
int		initialize_graphic(t_fract *f);	// Graphic window initialization.
int		keypress(int key, void *param);	// Graphic window keyboard controls.
size_t	ft_strlen(const char *s);		// Measure string length.
int		f_ai(const char *str);			// 'AtoI', ASCII to integer.
#endif
