/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 15:50:27 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 16:10:50 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void				test_draw_bezier_unicolor(t_image *image)
{
	t_color			white;
	t_list			*points;

	white = get_new_color(255, 255, 255, 1.0);

	points = NULL;
	add_position(get_new_fpos(100, 100), &points);
	add_position(get_new_fpos(0, 30), &points);
	add_position(get_new_fpos(100, 130), &points);

	/*t_list *it = points;
	while (it != NULL)
	{
		printf("%f, %f\n", ((t_fpos*)it->content)->x, ((t_fpos*)it->content)->y);
		it = it->next;
	}*/

	draw_bezier(image, points, white);

	del_pos_list(&points);
}

void				test_draw_bezier_gradient(t_image *image)
{
	(void)image;
}

void				test_draw_bezier_multicolor(t_image *image)
{
	(void)image;
}
