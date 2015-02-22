/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 23:07:40 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 17:45:54 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

#pragma message("need stdlib ???")
#include <stdlib.h>

void			draw_line(t_image *image, t_pos a, t_pos b, t_color color)
{
	t_list				gradient_lst;
	t_gradient			tmp_gradient;

	tmp_gradient = get_new_gradient(0.0, 1.0, color, color);
	gradient_lst.content = &tmp_gradient;
	gradient_lst.content_size = sizeof(tmp_gradient);
	gradient_lst.next = NULL;
	draw_line_gradient(image, a, b, &gradient_lst);
}

# pragma message("decalage binaire (/ 2)")
void			draw_line_gradient(t_image *img, t_pos a, t_pos b, t_list *lst)
{
	t_pos		d_s[2];
	int			error[2];
	double		ratio_dist[2];

	ratio_dist[1] = get_pos_distance(a, b);
	d_s[0].x = abs(b.x - a.x);
	d_s[1].x = a.x < b.x ? 1 : -1;
	d_s[0].y = abs(b.y - a.y);
	d_s[1].y = a.y < b.y ? 1 : -1;
	error[0] = (d_s[0].x > d_s[0].y ? d_s[0].x : -d_s[0].y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		ratio_dist[0] = get_pos_distance(a, b) / ratio_dist[1];
		put_pixel_image(img, a, get_gradient_color(lst, ratio_dist[0]));
		error[1] = error[0];
		if (error[1] > -d_s[0].x)
		{
			error[0] -= d_s[0].y;
			a.x += d_s[1].x;
		}
		if (error[1] < d_s[0].y)
		{
			error[0] += d_s[0].x;
			a.y += d_s[1].y;
		}
	}
}
