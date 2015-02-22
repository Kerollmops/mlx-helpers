/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:30:10 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 23:06:37 by crenault         ###   ########.fr       */
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
	t_fpos		d;
	t_fpos		end;
	t_fpos		pxl1;
	t_fpos		pxl2;
	float		xgap;
	double		gradient;
	double		intery;
	double		ratio;
	double		dist;
	t_pos		pos_tmp;

	dist = get_pos_distance(a, b);

	int steep = abs(b.y - a.y) > abs(b.x - a.x);

	if (steep)
	{
		swap(&a.x, &a.y);
		swap(&b.x, &b.y);
	}
	if (a.x > b.x)
	{
		swap(&a.x, &b.x);
		swap(&a.y, &b.y);
	}

	d.x = b.x - a.x;
	d.y = b.y - a.y;
	gradient = d.y / d.x;

	// handle first endpoint
	end.x = round(a.x);
	end.y = a.y + gradient * (end.x - a.x);
	xgap = reverse_floor_part(a.x + 0.5);
	pxl1.x = end.x; // this will be used in the main loop
	pxl1.y = int_part(end.y);
	if (steep)
	{
		//plot(pxl1.y, pxl1.x, reverse_floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl1.y, pxl1.x);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						reverse_floor_part(end.y) * xgap)
						);

		//plot(pxl1.y + 1, pxl1.x, floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl1.y + 1, pxl1.x);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						floor_part(end.y) * xgap)
						);
	}
	else
	{
		//plot(pxl1.x, pxl1.y , reverse_floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl1.x, pxl1.y);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						reverse_floor_part(end.y) * xgap)
						);

		//plot(pxl1.x, pxl1.y + 1, floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl1.x, pxl1.y + 1);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						floor_part(end.y) * xgap)
						);
	}
	intery = end.y + gradient; // first y-intersection for the main loop

	// handle second endpoint
	end.x = round(b.x);
	end.y = b.y + gradient * (end.x - b.x);
	xgap = floor_part(b.x + 0.5);
	pxl2.x = end.x; //this will be used in the main loop
	pxl2.y = int_part(end.y);
	if (steep)
	{
		//plot(pxl2.y, pxl2.x, reverse_floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl2.y, pxl2.x);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						reverse_floor_part(end.y) * xgap)
						);

		//plot(pxl2.y+1, pxl2.x, floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl2.y + 1, pxl2.x);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						floor_part(end.y) * xgap)
						);
	}
	else
	{
		//plot(pxl2.x, pxl2.y, reverse_floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl2.x, pxl2.y);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						reverse_floor_part(end.y) * xgap)
						);

		//plot(pxl2.x, pxl2.y + 1, floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl2.x, pxl2.y + 1);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
						get_pixel_image(i, pos_tmp),
						floor_part(end.y) * xgap)
						);
	}

	// main loop
	int x = pxl1.x + 1;
	while (x < pxl2.x - 1)
	{
		if (steep)
		{
			//plot(int_part(intery) , x, reverse_floor_part(intery));
			pos_tmp = get_new_pos(int_part(intery), x);
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
							get_pixel_image(i, pos_tmp),
							reverse_floor_part(intery))
							);

			//plot(int_part(intery) + 1, x, floor_part(intery));
			pos_tmp = get_new_pos(int_part(intery) + 1, x);
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
							get_pixel_image(i, pos_tmp),
							floor_part(intery))
							);
		}
		else
		{
			//plot(x, int_part(intery), reverse_floor_part(intery));
			pos_tmp = get_new_pos(x, int_part(intery));
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
							get_pixel_image(i, pos_tmp),
							reverse_floor_part(intery))
							);

			//plot(x, int_part(intery) + 1, floor_part(intery));
			pos_tmp = get_new_pos(x, int_part(intery) + 1);
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
							get_pixel_image(i, pos_tmp),
							floor_part(intery))
							);
		}
		intery = intery + gradient;
		x++;
	}
}
