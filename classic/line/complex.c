/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 00:34:58 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 10:12:51 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

// http://cubic.org/docs/bezier.htm
void			draw_bezier_func(t_image *image, t_list *points, t_list *grads,
									void (*f)(t_image*, t_pos, t_pos, t_color))
{
	const uint	nb_seg = 20;
	double		t;
	t_fpos		last;
	t_fpos		act;
	uint		i;
	uint		j;
	t_list		*dup_points;
	t_list		*dup_it;
	t_fpos		*tmp_ptr;
	t_fpos		tmp;

	if (ft_lstlen(points) < 2) {

		if (MLX_HELPERS_DEBUG == 1)
			ft_putendl_fd("draw_bezier: bad number of points", 2);
		return ;
	}
	i = 0;
	while (i <= nb_seg)
	{
		dup_points = ft_lstdup(points);
		t = (double)i / (double)nb_seg;
		while (ft_lstlen(dup_points) > 1)
		{
			dup_it = dup_points;
			j = 0;
			while (j < (ft_lstlen(dup_points) - 1))
			{
				tmp = lerp(	*(t_fpos*)get_pos_node(dup_points, j)->content,
							*(t_fpos*)get_pos_node(dup_points, j + 1)->content,
							t);
				tmp_ptr = ((t_fpos*)get_pos_node(dup_points, j)->content);
				tmp_ptr->x = tmp.x;
				tmp_ptr->y = tmp.y;
				j++;
			}
			ft_lstpopback(&dup_points);
			dup_it = dup_it->next;
		}
		act = *((t_fpos*)dup_points->content);
		if (i > 0)
		{
			(f)(image, get_new_pos(last.x, last.y), get_new_pos(act.x, act.y),
					get_gradient_color(grads, t));
		}
		last = act;
		i++;
		del_pos_list(&dup_points);
	}
	(f)(image, get_new_pos(last.x, last.y), get_new_pos(act.x, act.y),
			get_gradient_color(grads, t));
}

void			draw_bezier(t_image *image, t_list *points, t_color color)
{
	t_list				gradient_lst;
	t_gradient			tmp_gradient;

	tmp_gradient = get_new_gradient(0.0, 1.0, color, color);
	gradient_lst.content = &tmp_gradient;
	gradient_lst.content_size = sizeof(tmp_gradient);
	gradient_lst.next = NULL;
	draw_bezier_gradient(image, points, &gradient_lst);
}

void			draw_bezier_gradient(t_image *image, t_list *points, t_list *g)
{
	draw_bezier_func(image, points, g, draw_line);
}

void			draw_bezier_aa(t_image *image, t_list *points, t_color c)
{
	t_list				gradient_lst;
	t_gradient			tmp_gradient;

	tmp_gradient = get_new_gradient(0.0, 1.0, c, c);
	gradient_lst.content = &tmp_gradient;
	gradient_lst.content_size = sizeof(tmp_gradient);
	gradient_lst.next = NULL;
	draw_bezier_aa_gradient(image, points, &gradient_lst);
}

void			draw_bezier_aa_gradient(t_image *img, t_list *pts, t_list *g)
{
	draw_bezier_func(img, pts, g, draw_line_aa);
}
