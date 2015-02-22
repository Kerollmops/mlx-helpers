/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:30:10 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 00:13:23 by crenault         ###   ########.fr       */
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

// http://members.chello.at/easyfilter/bresenham.html
void			draw_line_aa_gradient(t_image *i, t_pos a, t_pos b, t_list *l)
{
	t_fpos		d;
	t_fpos		end;
	t_pos		pxl1;
	t_pos		pxl2;
	t_pos		pos_tmp;
	double		ratio;
	double		dist;

	dist = get_pos_distance(a, b);

	d.x = b.x - a.x;
	d.y = b.y - a.y;

	// if same position
	if (a.x == b.x && a.y == b.y)
	{
		pos_tmp = get_new_pos(a.x, a.y);
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, 0.5),
									get_pixel_image(i, pos_tmp),
									1.0
								)
						);
		return ;
	}

	if (fabs(d.x) > fabs(d.y))
	{
		if (b.x < a.x)
		{
			swap_int(&a.x, &b.x);
			swap_int(&a.y, &b.y);
		}

		double gradient = d.y / d.x;
		end.x = round(a.x);
		end.y = a.y + gradient * (end.x - a.x);
		double xgap = reverse_floor_part(a.x + 0.5);
		pxl1.x = end.x;
		pxl1.y = int_part(end.y);

		//plot_(pxl1.x, pxl1.y, reverse_floor_part(end.y)*xgap);
		pos_tmp = get_new_pos(pxl1.x, pxl1.y);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									reverse_floor_part(end.y) * xgap
								)
						);

		//plot_(pxl1.x, pxl1.y+1, floor_part(end.y)*xgap);
		pos_tmp = get_new_pos(pxl1.x, pxl1.y + 1);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									floor_part(end.y) * xgap
								)
						);

		double intery = end.y + gradient;

		end.x = round(b.x);
		end.y = b.y + gradient*(end.x - b.x);
		xgap = floor_part(b.x+0.5);
		pxl2.x = end.x;
		pxl2.y = int_part(end.y);

		//plot_(pxl2.x, pxl2.y, reverse_floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl2.x, pxl2.y);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									reverse_floor_part(end.y) * xgap
								)
						);

		//plot_(pxl2.x, pxl2.y + 1, floor_part(end.y) * xgap);
		pos_tmp = get_new_pos(pxl2.x, pxl2.y + 1);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									floor_part(end.y) * xgap
								)
						);

		int x;
		for (x = pxl1.x + 1; x <= (pxl2.x - 1); x++)
		{
			//plot_(x, int_part(intery), reverse_floor_part(intery));
			pos_tmp = get_new_pos(x, int_part(intery));
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
										get_pixel_image(i, pos_tmp),
										reverse_floor_part(intery)
									)
							);

			//plot_(x, int_part(intery) + 1, floor_part(intery));
			pos_tmp = get_new_pos(x, int_part(intery) + 1);
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
										get_pixel_image(i, pos_tmp),
										floor_part(intery)
									)
							);

			intery += gradient;
		}
	}
	else
	{
		if (b.y < a.y)
		{
			swap_int(&a.x, &b.x);
			swap_int(&a.y, &b.y);
		}

		double gradient = d.x / d.y;
		end.y = round(a.y);
		end.x = a.x + gradient*(end.y - a.y);
		double ygap = reverse_floor_part(a.y + 0.5);
		pxl1.y = end.y;
		pxl1.x = int_part(end.x);

		//plot_(pxl1.x, pxl1.y, reverse_floor_part(end.x)*ygap);
		pos_tmp = get_new_pos(pxl1.x, pxl1.y);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									reverse_floor_part(end.x) * ygap
								)
						);

		//plot_(pxl1.x, pxl1.y+1, floor_part(end.x)*ygap);
		pos_tmp = get_new_pos(pxl1.x, pxl1.y + 1);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									reverse_floor_part(end.x) * ygap
								)
						);

		double interx = end.x + gradient;

		end.y = round(b.y);
		end.x = b.x + gradient*(end.y - b.y);
		ygap = floor_part(b.y+0.5);
		pxl2.y = end.y;
		pxl2.x = int_part(end.x);

		//plot_(pxl2.x, pxl2.y, reverse_floor_part(end.x) * ygap);
		pos_tmp = get_new_pos(pxl2.x, pxl2.y);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									reverse_floor_part(end.x) * ygap
								)
						);

		//plot_(pxl2.x, pxl2.y + 1, floor_part(end.x) * ygap);
		pos_tmp = get_new_pos(pxl2.x, pxl2.y + 1);
		ratio = get_pos_distance(pos_tmp, b) / dist;
		put_pixel_image(i, pos_tmp,
						get_scalar(get_gradient_color(l, ratio),
									get_pixel_image(i, pos_tmp),
									reverse_floor_part(end.x) * ygap
								)
						);

		int	y;
		for (y = pxl1.y + 1; y <= (pxl2.y - 1); y++)
		{
			//plot_(int_part(interx), y, reverse_floor_part(interx));
			pos_tmp = get_new_pos(int_part(interx), y);
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
										get_pixel_image(i, pos_tmp),
										reverse_floor_part(interx)
									)
							);

			//plot_(int_part(interx) + 1, y, floor_part(interx));
			pos_tmp = get_new_pos(int_part(interx) + 1, y);
			ratio = get_pos_distance(pos_tmp, b) / dist;
			put_pixel_image(i, pos_tmp,
							get_scalar(get_gradient_color(l, ratio),
										get_pixel_image(i, pos_tmp),
										floor_part(interx)
									)
							);

			interx += gradient;
		}
	  }

	/*//plot(x, int_part(intery) + 1, floor_part(intery));
	pos_tmp = get_new_pos(x, int_part(intery) + 1);
	ratio = get_pos_distance(pos_tmp, b) / dist;
	put_pixel_image(i, pos_tmp,
					get_scalar(get_gradient_color(l, ratio),
					get_pixel_image(i, pos_tmp),
					floor_part(intery))
					);*/
}
