/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 22:52:54 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 00:18:09 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_helpers.h"

t_color			get_scalar(t_color a, t_color b, double ratio)
{
	t_color		color;

	color.r = b.r * ratio + a.r * (1.0 - ratio);
	color.g = b.g * ratio + a.g * (1.0 - ratio);
	color.b = b.b * ratio + a.b * (1.0 - ratio);
	return (color);
}

t_gradient		get_new_gradient(double min, double max, t_color start,
									t_color stop)
{
	t_gradient	gradient;

	# pragma message("limit min and max 0 <= min|max <= 1 ???")
	gradient.min = min;
	gradient.max = max;
	gradient.start = start;
	gradient.stop = stop;
	return (gradient);
}

void			add_gradient_color(t_gradient grad, t_list **lst)
{
	ft_lstpush(lst, ft_lstnew(&grad, sizeof(t_gradient)));
}

t_color			get_gradient_color(t_list *lst, double ratio)
{
	t_color			color;
	t_list			*it;
	t_gradient		*gradcol;
	double			perc;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	it = lst;
	while (it != NULL)
	{
		gradcol = (t_gradient*)it->content;
		if (ratio >= gradcol->min && ratio <= gradcol->max)
		{
			perc = (ratio - gradcol->min) / (gradcol->max - gradcol->min);
			color = get_scalar(gradcol->start, gradcol->stop, perc);
			return (color);
		}
		it = it->next;
	}
	# pragma message("don't find ratio area what to do ???")
	return (color);
}
