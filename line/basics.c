/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 23:07:40 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 00:16:28 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_helpers.h"

#pragma message("need stdlib ???")
#include <stdlib.h>

# pragma message("decalage binaire (/ 2)")
void			draw_line(t_image *image, t_pos a, t_pos b, t_color color)
{
	t_pos		d;
	t_pos		s;
	int			error[2];

	d.x = abs(b.x - a.x);
	s.x = a.x < b.x ? 1 : -1;
	d.y = abs(b.y - a.y);
	s.y = a.y < b.y ? 1 : -1;
	error[0] = (d.x > d.y ? d.x : -d.y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		put_pixel_image(image, a, color);
		error[1] = error[0];
		if (error[1] > -d.x)
		{
			error[0] -= d.y;
			a.x += s.x;
		}
		if (error[1] < d.y)
		{
			error[0] += d.x;
			a.y += s.y;
		}
	}
}

void			draw_line_aa(t_image *image, t_pos a, t_pos b, t_list *gradlst)
{
	t_pos		d;
	t_pos		s;
	int			error[2];
	double		ratio;
	double		big_dist;

	big_dist = get_pos_distance(a, b);
	d.x = abs(b.x - a.x);
	s.x = a.x < b.x ? 1 : -1;
	d.y = abs(b.y - a.y);
	s.y = a.y < b.y ? 1 : -1;
	error[0] = (d.x > d.y ? d.x : -d.y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		ratio = get_pos_distance(a, b) / big_dist;
		put_pixel_image(image, a, get_gradient_color(gradlst, ratio));
		error[1] = error[0];
		if (error[1] > -d.x)
		{
			error[0] -= d.y;
			a.x += s.x;
		}
		if (error[1] < d.y)
		{
			error[0] += d.x;
			a.y += s.y;
		}
	}
}
