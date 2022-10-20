/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_uncontrolled_element_of_life.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviholai <aviholai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:59:27 by aviholai          #+#    #+#             */
/*   Updated: 2022/10/20 15:23:21 by aviholai         ###   ########.fr       */
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

# define T_GREY "\033[0;37m"	// Grey terminal color.
# define T_OG "\033[1;33m"		// Orange bold terminal color.
# define T_YELL "\033[0;33m"	// Yellow terminal color.
# define T_RED "\033[0;31m"		// Red terminal color.
# define T_0 "\033[0m"			// Default terminal color.

int		main(int argc, char **argv);	// Main function.
size_t	ft_strlen(const char *s);		// Measure string length.
int		f_ai(const char *str);			// 'AtoI', ASCII to integer.
#endif
