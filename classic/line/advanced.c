/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:30:10 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 14:09:43 by crenault         ###   ########.fr       */
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

static void		_plot(t_image *i, t_pos pos, t_list *l, double ratios[2])
{
	put_pixel_image(i, pos, get_scalar(get_gradient_color(l, ratios[0]),
										get_pixel_image(i, pos), ratios[1]));
}

static void		_xgap_part(t_image *i, t_pos a, t_pos b, t_list *l)
{
	t_fpos			d;
	t_fpos			end;
	t_pos			pxl1;
	t_pos			pxl2;
	t_pos			pos_tmp;
	double			ratios[2];
	double			dist;
	double			gradient;
	double			xgap;
	double			intery;
	int				x;

	dist = get_pos_distance(a, b);

	d.x = b.x - a.x;
	d.y = b.y - a.y;

	if (b.x < a.x)
	{
		swap_int(&a.x, &b.x);
		swap_int(&a.y, &b.y);
	}

	gradient = d.y / d.x;
	end.x = round(a.x);
	end.y = a.y + gradient * (end.x - a.x);
	xgap = reverse_floor_part(a.x + 0.5);
	pxl1.x = end.x;
	pxl1.y = int_part(end.y);

	//
	ratios[0] = get_pos_distance(pxl1, b) / dist;
	ratios[1] = reverse_floor_part(end.y) * xgap;
	_plot(i, pxl1, l, ratios);

	//
	pos_tmp = get_new_pos(pxl1.x, pxl1.y + 1); // y += ! ?
	ratios[0] = get_pos_distance(pos_tmp, b) / dist;
	ratios[1] = floor_part(end.y) * xgap;
	_plot(i, pos_tmp, l, ratios);

	intery = end.y + gradient;

	end.x = round(b.x);
	end.y = b.y + gradient*(end.x - b.x);
	xgap = floor_part(b.x+0.5);
	pxl2.x = end.x;
	pxl2.y = int_part(end.y);

	//
	ratios[0] = get_pos_distance(pxl2, b) / dist;
	ratios[1] = reverse_floor_part(end.y) * xgap;
	_plot(i, pxl2, l, ratios);

	//
	pos_tmp = get_new_pos(pxl2.x, pxl2.y + 1); // y += ! ?
	ratios[0] = get_pos_distance(pos_tmp, b) / dist;
	ratios[1] = floor_part(end.y) * xgap;
	_plot(i, pos_tmp, l, ratios);

	x = pxl1.x + 1;
	while (x <= pxl2.x - 1)
	{
		//
		pos_tmp = get_new_pos(x, int_part(intery));
		ratios[0] = get_pos_distance(pos_tmp, b) / dist;
		ratios[1] = reverse_floor_part(intery);
		_plot(i, pos_tmp, l, ratios);

		//
		pos_tmp = get_new_pos(x, int_part(intery) + 1);
		ratios[0] = get_pos_distance(pos_tmp, b) / dist;
		ratios[1] = floor_part(intery);
		_plot(i, pos_tmp, l, ratios);

		intery += gradient;
		++x;
	}
}

static void		_ygap_part(t_image *i, t_pos a, t_pos b, t_list *l)
{
	t_fpos			d;
	t_fpos			end;
	t_pos			pxl1;
	t_pos			pxl2;
	t_pos			pos_tmp;
	double			ratios[2];
	double			dist;
	double			gradient;
	double			ygap;
	double			interx;
	int				y;

	dist = get_pos_distance(a, b);

	d.x = b.x - a.x;
	d.y = b.y - a.y;

	if (b.y < a.y)
	{
		swap_int(&a.x, &b.x);
		swap_int(&a.y, &b.y);
	}

	gradient = d.x / d.y;
	end.y = round(a.y);
	end.x = a.x + gradient*(end.y - a.y);
	ygap = reverse_floor_part(a.y + 0.5);
	pxl1.y = end.y;
	pxl1.x = int_part(end.x);

	//
	ratios[0] = get_pos_distance(pxl1, b) / dist;
	ratios[1] = reverse_floor_part(end.x) * ygap;
	_plot(i, pxl1, l, ratios);

	//
	pos_tmp = get_new_pos(pxl1.x, pxl1.y + 1); // y += ! ?
	ratios[0] = get_pos_distance(pos_tmp, b) / dist;
	ratios[1] = reverse_floor_part(end.x) * ygap;
	_plot(i, pos_tmp, l, ratios);

	interx = end.x + gradient;

	end.y = round(b.y);
	end.x = b.x + gradient*(end.y - b.y);
	ygap = floor_part(b.y+0.5);
	pxl2.y = end.y;
	pxl2.x = int_part(end.x);

	//
	ratios[0] = get_pos_distance(pxl2, b) / dist;
	ratios[1] = reverse_floor_part(end.x) * ygap;
	_plot(i, pxl2, l, ratios);

	//
	pos_tmp = get_new_pos(pxl2.x, pxl2.y + 1); // y += ! ?
	ratios[0] = get_pos_distance(pos_tmp, b) / dist;
	ratios[1] = reverse_floor_part(end.x) * ygap;
	_plot(i, pos_tmp, l, ratios);

	y = pxl1.y + 1;
	while (y <= pxl2.y - 1)
	{
		//
		pos_tmp = get_new_pos(int_part(interx), y);
		ratios[0] = get_pos_distance(pos_tmp, b) / dist;
		ratios[1] = reverse_floor_part(interx);
		_plot(i, pos_tmp, l, ratios);

		//
		pos_tmp = get_new_pos(int_part(interx) + 1, y);
		ratios[0] = get_pos_distance(pos_tmp, b) / dist;
		ratios[1] = floor_part(interx);
		_plot(i, pos_tmp, l, ratios);

		interx += gradient;
		++y;
	}
}

// http://members.chello.at/easyfilter/bresenham.html
void			draw_line_aa_gradient(t_image *i, t_pos a, t_pos b, t_list *l)
{
	t_fpos			d;
	double			ratios[2];

	d.x = b.x - a.x;
	d.y = b.y - a.y;

	// if same position
	if (a.x == b.x && a.y == b.y)
	{
		ratios[0] = 0.5;
		ratios[1] = 1.0;
		_plot(i, a, l, ratios);
	}
	else if (fabs(d.x) > fabs(d.y))
	{
		_xgap_part(i, a, b, l);
	}
	else
	{
		_ygap_part(i, a, b, l);
	}
}
