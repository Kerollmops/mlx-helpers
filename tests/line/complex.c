/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 15:50:27 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 18:02:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void				test_draw_bezier_unicolor(t_image *image)
{
	t_color			white;
	t_list			*points;

	white = get_new_color(255, 255, 255, 1.0);

	points = NULL;
	add_position(get_new_fpos(80, 100), &points);
	add_position(get_new_fpos(0, 30), &points);
	add_position(get_new_fpos(0, 230), &points);
	add_position(get_new_fpos(100, 60), &points);
	add_position(get_new_fpos(120, 100), &points);
	draw_bezier(image, points, white);
	del_pos_list(&points);
}

void				test_draw_bezier_gradient(t_image *image)
{
	t_list			*gradient_lst;
	t_list			*points;

	gradient_lst = NULL;
	add_gradient_color(	get_new_gradient(0.0, 1.0,
											get_new_color(255, 255, 255, 1.0),		// white
											get_new_color(0, 0, 0, 1.0)),			// black
						&gradient_lst);

	points = NULL;
	add_position(get_new_fpos(80 + 120, 100), &points);
	add_position(get_new_fpos(0 + 120, 30), &points);
	add_position(get_new_fpos(0 + 120, 230), &points);
	add_position(get_new_fpos(100 + 120, 60), &points);
	add_position(get_new_fpos(120 + 120, 100), &points);

	draw_bezier_gradient(image, points, gradient_lst);

	del_gradient_list(&gradient_lst);
	del_pos_list(&points);
}

void				test_draw_bezier_multicolor(t_image *image)
{
	t_list			*gradient_lst;
	t_list			*points;

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

	points = NULL;
	add_position(get_new_fpos(80 + 240, 100), &points);
	add_position(get_new_fpos(0 + 240, 30), &points);
	add_position(get_new_fpos(0 + 240, 230), &points);
	add_position(get_new_fpos(100 + 240, 60), &points);
	add_position(get_new_fpos(120 + 240, 100), &points);

	draw_bezier_gradient(image, points, gradient_lst);

	del_gradient_list(&gradient_lst);
	del_pos_list(&points);
}

/*
** antialised
*/
void				test_draw_bezier_aa_unicolor(t_image *image)
{
	t_color			white;
	t_list			*points;

	white = get_new_color(255, 255, 255, 1.0);

	points = NULL;
	add_position(get_new_fpos(80, 100 + 70), &points);
	add_position(get_new_fpos(0, 30 + 70), &points);
	add_position(get_new_fpos(0, 230 + 70), &points);
	add_position(get_new_fpos(100, 60 + 70), &points);
	add_position(get_new_fpos(120, 100 + 70), &points);
	draw_bezier_aa(image, points, white);
	del_pos_list(&points);
}

void				test_draw_bezier_aa_gradient(t_image *image)
{
		t_list			*gradient_lst;
	t_list			*points;

	gradient_lst = NULL;
	add_gradient_color(	get_new_gradient(0.0, 1.0,
											get_new_color(255, 255, 255, 1.0),		// white
											get_new_color(0, 0, 0, 1.0)),			// black
						&gradient_lst);

	points = NULL;
	add_position(get_new_fpos(80 + 120, 100 + 70), &points);
	add_position(get_new_fpos(0 + 120, 30 + 70), &points);
	add_position(get_new_fpos(0 + 120, 230 + 70), &points);
	add_position(get_new_fpos(100 + 120, 60 + 70), &points);
	add_position(get_new_fpos(120 + 120, 100 + 70), &points);

	draw_bezier_aa_gradient(image, points, gradient_lst);

	del_gradient_list(&gradient_lst);
	del_pos_list(&points);
}

void				test_draw_bezier_aa_multicolor(t_image *image)
{
		t_list			*gradient_lst;
	t_list			*points;

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

	points = NULL;
	add_position(get_new_fpos(80 + 240, 100 + 70), &points);
	add_position(get_new_fpos(0 + 240, 30 + 70), &points);
	add_position(get_new_fpos(0 + 240, 230 + 70), &points);
	add_position(get_new_fpos(100 + 240, 60 + 70), &points);
	add_position(get_new_fpos(120 + 240, 100 + 70), &points);

	draw_bezier_aa_gradient(image, points, gradient_lst);

	del_gradient_list(&gradient_lst);
	del_pos_list(&points);
}
