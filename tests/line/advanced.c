/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:01:39 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 18:04:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void				test_draw_aa_unicolor_line(t_image *image)
{
	draw_line_aa(	image,
					get_new_pos(10, 10),
					get_new_pos(30, 70),
					get_new_color(255, 255, 255, 1.0));		// white
}

void				test_draw_aa_gradient_line(t_image *image)
{
	t_list		*gradient_lst;

	gradient_lst = NULL;
	add_gradient_color(	get_new_gradient(0.0, 1.0,
											get_new_color(255, 255, 255, 1.0),		// white
											get_new_color(0, 0, 0, 1.0)),			// black
						&gradient_lst);
	draw_line_aa_gradient(	image,
							get_new_pos(20 + 20, 10), get_new_pos(40 + 20, 70),
							gradient_lst);
	del_gradient_list(&gradient_lst);
}

void				test_draw_aa_multicolor_line(t_image *image)
{
	t_list		*gradient_lst;

	gradient_lst = NULL;
	add_gradient_color(	get_new_gradient(0.0, 0.2,
											get_new_color(255, 255, 0, 1.0),	// yellow
											get_new_color(255, 0, 0, 1.0)	// red
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.2, 0.4,
											get_new_color(0, 255, 0, 1.0),	// green
											get_new_color(255, 255, 0, 1.0)	// yellow
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.4, 0.6,
											get_new_color(0, 255, 255, 1.0),	// cyan
											get_new_color(0, 255, 0, 1.0)	// green
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.6, 0.8,
											get_new_color(0, 0, 255, 1.0),	// blue
											get_new_color(0, 255, 255, 1.0)	// cyan
										),
						&gradient_lst);
	add_gradient_color(	get_new_gradient(0.8, 1.0,
											get_new_color(255, 0, 255, 1.0),	// magenta
											get_new_color(0, 0, 255, 1.0)	// blue
										),
						&gradient_lst);
	draw_line_aa_gradient(	image,
						get_new_pos(30 + 40, 10), get_new_pos(50 + 40, 70),
						gradient_lst);
	del_gradient_list(&gradient_lst);
}
