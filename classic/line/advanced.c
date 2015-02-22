/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:30:10 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 18:22:59 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "../../mlx_helpers.h"

void			draw_line_aa(t_image *image, t_pos a, t_pos b, t_color color)
{
	t_list				gradient_lst;
	t_gradient			tmp_gradient;

	tmp_gradient = get_new_gradient(0.0, 1.0, color, color);
	gradient_lst.content = &tmp_gradient;
	gradient_lst.content_size = sizeof(tmp_gradient);
	gradient_lst.next = NULL;
	draw_line_aa_gradient(image, a, b, &gradient_lst);
}

void			draw_line_aa_gradient(t_image *i, t_pos a, t_pos b, t_list *l)
{
	t_fpos			d;
	t_fpos			end;
	t_fpos			pxl1;
	t_fpos			pxl2;
	double			xgap;
	double			intery;
	double			gradient;
	double			dist;
	double			ratio;

	int steep = abs(b.y - a.y) > abs(b.x - a.x);

	if (steep) {

		swap(&a.x, &a.y);
		swap(&b.x, &b.y);
	}
	if (a.x > b.x) {

		swap(&a.x, &b.x);
		swap(&a.y, &b.y);
	}

	dist = get_pos_distance(a, b);
	d.x = b.x - a.x;
	d.y = b.y - a.y;

	gradient = d.y / d.x;

	end.x = round(a.x);
	end.y = a.y + gradient * (end.x - a.x);

	xgap = reverse_floor_part(a.x + 0.5);

	pxl1.x = end.x;
	pxl1.y = int_part(end.y);

	t_pos		pos_tmp;
	double		perc_tmp;
	pos_tmp.x = pxl1.x;
	pos_tmp.y = pxl1.y;
	perc_tmp = reverse_floor_part(end.y) * xgap;
	ratio = get_pos_distance(pos_tmp, b) / dist;
	put_pixel_image(i, pos_tmp,
					get_scalar(get_gradient_color(l, ratio),
					get_pixel_image(i, pos_tmp), perc_tmp)
					);

	pos_tmp.y += 1;
	perc_tmp = floor_part(end.y) * xgap;
	ratio = get_pos_distance(pos_tmp, b) / dist;
	put_pixel_image(i, pos_tmp,
					get_scalar(get_gradient_color(l, ratio),
					get_pixel_image(i, pos_tmp), perc_tmp)
					);

	intery = end.y + gradient;

	end.x = round(b.x);
	end.y = b.y + gradient * (end.x - b.x);
	double		tmp_fp;
	tmp_fp = b.x + 0.5;
	xgap = floor_part(tmp_fp);
	pxl2.x = end.x;
	pxl2.y = int_part(end.y);

	pos_tmp.x = pxl2.x;
	pos_tmp.y = pxl2.y;
	perc_tmp = reverse_floor_part(end.y) * xgap;
	ratio = get_pos_distance(pos_tmp, b) / dist;
	put_pixel_image(i, pos_tmp,
					get_scalar(get_gradient_color(l, ratio),
					get_pixel_image(i, pos_tmp), perc_tmp)
					);

	pos_tmp.y += 1;
	perc_tmp = floor_part(end.y) * xgap;
	ratio = get_pos_distance(pos_tmp, b) / dist;
	put_pixel_image(i, pos_tmp,
					get_scalar(get_gradient_color(l, ratio),
					get_pixel_image(i, pos_tmp), perc_tmp)
					);

	int			x;
	x = pxl1.x + 1;
	while (x <= (int)(pxl2.x - 1))
	{
		pos_tmp.x = x;
		pos_tmp.y = int_part(intery);
		perc_tmp = reverse_floor_part(intery);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp), perc_tmp)
					);

		pos_tmp.y += 1;
		perc_tmp = floor_part(intery);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp), perc_tmp)
					);

		intery += gradient;
		x++;
	}
}
