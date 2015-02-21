/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 11:00:43 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 16:01:27 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void				draw_unicolor_line(t_image *image)
{
	draw_line(	image,
				get_new_pos(10, 10), get_new_pos(10, 70),
				get_new_color(255, 255, 255));	// white
}

void				draw_gradient_line(t_image *image)
{
	t_list		*gradient_lst;

	gradient_lst = NULL;
	add_gradient_color(	get_new_gradient(0.0, 1.0,
											get_new_color(0, 0, 0),			// black
											get_new_color(255, 255, 255)),	// white
						&gradient_lst);
	draw_line_gradient(	image,
						get_new_pos(10 + 20, 10), get_new_pos(10 + 20, 70),
						gradient_lst);
}

void				draw_multicolor_line(t_image *image)
{
	t_list		*gradient_lst;

	gradient_lst = NULL;
	add_gradient_color(	get_new_gradient(0.0, 0.2,
											get_new_color(255, 0, 0),	// red
											get_new_color(255, 255, 0)	// yellow
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.2, 0.4,
											get_new_color(255, 255, 0),	// yellow
											get_new_color(0, 255, 0)	// green
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.4, 0.6,
											get_new_color(0, 255, 0),	// green
											get_new_color(0, 255, 255)	// cyan
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.6, 0.8,
											get_new_color(0, 255, 255),	// cyan
											get_new_color(0, 0, 255)	// blue
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.8, 1.0,
											get_new_color(0, 0, 255),	// blue
											get_new_color(255, 0, 255)	// magenta
										),
						&gradient_lst);
	draw_line_gradient(	image,
					get_new_pos(10 + 40, 10), get_new_pos(10 + 40, 70),
					gradient_lst);
}
