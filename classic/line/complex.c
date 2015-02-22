/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 00:34:58 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 16:13:42 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

# pragma message("position/advanced.c")
static t_fpos	lerp(t_fpos a, t_fpos b, const double t)
{
	t_fpos		dest;

	dest.x = a.x + (b.x - a.x) * t;
	dest.y = a.y + (b.y - a.y) * t;
	return (dest);
}

// http://cubic.org/docs/bezier.htm
void			draw_bezier(t_image *image, t_list *points, t_color color)
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
		#pragma message("duplicate linked list")
		//dup_points = points;
		dup_points = ft_lstdup(points);

		t = (double)i / (double)nb_seg;

		while (ft_lstlen(dup_points) > 1)
		{
			// get first element to iterate over the dup_points
			//itr = dup_points.begin();
			dup_it = dup_points;

			/*t_list *it = dup_points;
			while (it != NULL)
			{
				printf("%f, %f\n", ((t_fpos*)it->content)->x, ((t_fpos*)it->content)->y);
				it = it->next;
			}*/

			j = 0;
			while (j < (ft_lstlen(dup_points) - 1))
			{
				tmp = lerp(	*(t_fpos*)get_pos_node(dup_points, j)->content,
							*(t_fpos*)get_pos_node(dup_points, j + 1)->content,
							t);
				tmp_ptr = ((t_fpos*)get_pos_node(dup_points, j)->content);
				tmp_ptr->x = tmp.x;
				tmp_ptr->y = tmp.y;

				//printf("%f, %f\n", tmp.x, tmp.y);

				j++;
			}
			// delete the last
			//dup_points.pop_back();
			ft_lstpopback(&dup_points);

			// move in dup_points
			dup_it = dup_it->next;

			//++i;
		}
		// act equal first pos
		//act = dup_points.front();
		act = *((t_fpos*)dup_points->content);

		if (i > 0)
		{
			draw_line(image, get_new_pos(last.x, last.y),
						get_new_pos(act.x, act.y), color);
		}
		last = act;
		i++;
		del_pos_list(&dup_points);
	}
	draw_line(image, get_new_pos(last.x, last.y),
				get_new_pos(act.x, act.y), color);
}

void			draw_bezier_gradient(t_image *image, t_list *points, t_color c)
{
	(void)image;
	(void)points;
	(void)c;
}

void			draw_bezier_aa(t_image *image, t_list *points, t_color c)
{
	(void)image;
	(void)points;
	(void)c;
}

void			draw_bezier_aa_gradient(t_image *img, t_list *pts, t_color c)
{
	(void)img;
	(void)pts;
	(void)c;
}
