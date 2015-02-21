/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:30:10 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 19:18:21 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_helpers.h"

#pragma message("need stdlib ???")
#include <stdlib.h>
#pragma message("need math ???")
#include <math.h>

void			draw_line_aa(t_image *image, t_pos a, t_pos b, t_color color)
{
	t_dblpos		d;
	t_dblpos		end;
	t_dblpos		pxl1;
	t_dblpos		pxl2;
	double			xgap;
	double			intery;
	double			gradient;

	d.x = b.x - a.x;
	d.y = b.y - a.y;
	if (abs(b.x - a.x) > abs(b.y - a.y))
	{
		if (b.x < a.x)
		{
			swap(&a.x, &b.x);
			swap(&a.y, &b.y);
		}
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
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

		pos_tmp.y += 1;
		perc_tmp = floor_part(end.y) * xgap;
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
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
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

		pos_tmp.y += 1;
		perc_tmp = floor_part(end.y) * xgap;
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

		int			x;
		x = pxl1.x + 1;
		while (x <= (int)(pxl2.x - 1))
		{
			pos_tmp.x = x;
			pos_tmp.y = int_part(intery);
			perc_tmp = reverse_floor_part(intery);
			put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

			pos_tmp.y += 1;
			perc_tmp = floor_part(intery);
			put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

			intery += gradient;
			x++;
		}
	}
	else
	{
		if (b.y < a.y)
		{
			swap(&a.y, &b.y);
			swap(&a.x, &b.x);
		}
		gradient = d.x / d.y;

		end.y = round(a.y);
		end.x = a.x + gradient * (end.y - a.y);

		double tmp;
		tmp = a.y + 0.5;
		xgap = reverse_floor_part(tmp);

		pxl1.y = end.y;
		pxl1.x = int_part(end.x);

		t_pos		pos_tmp;
		double		perc_tmp;
		pos_tmp.y = pxl1.y;
		pos_tmp.x = pxl1.x;
		perc_tmp = reverse_floor_part(end.x) * xgap;
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

		pos_tmp.x += 1;
		perc_tmp = floor_part(end.x) * xgap;
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

		intery = end.x + gradient;

		end.y = round(b.y);
		end.x = b.x + gradient * (end.y - b.y);
		double		tmp_fp;
		tmp_fp = b.y + 0.5;
		xgap = floor_part(tmp_fp);
		pxl2.y = end.y;
		pxl2.x = int_part(end.x);

		pos_tmp.y = pxl2.y;
		pos_tmp.x = pxl2.x;
		perc_tmp = reverse_floor_part(end.x) * xgap;
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

		pos_tmp.x += 1;
		perc_tmp = floor_part(end.x) * xgap;
		put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

		int			x;
		x = pxl1.y + 1;
		while (x <= (int)(pxl2.y - 1))
		{
			pos_tmp.y = x;
			pos_tmp.x = int_part(intery);
			perc_tmp = reverse_floor_part(intery);
			put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

			pos_tmp.x += 1;
			perc_tmp = floor_part(intery);
			put_pixel_image(image, pos_tmp,
						get_scalar(color, get_new_color(0, 0, 0), perc_tmp)
						);

			intery += gradient;
			x++;
		}
	}
}

void			draw_line_aa_gradient(t_image *i, t_pos a, t_pos b, t_list *l)
{
	(void)i;
	(void)a;
	(void)b;
	(void)l;
}
