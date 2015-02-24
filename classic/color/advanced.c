/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 22:52:54 by crenault          #+#    #+#             */
/*   Updated: 2015/02/24 13:52:58 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../classic_mlx_helpers.h"

t_color			get_scalar(t_color a, t_color b, double ratio)
{
	t_color		color;

	ratio = (ratio > 1.0f) ? 1.0f : (ratio < 0.0f) ? 0.0f : ratio;
	color.r = (a.r * ratio) * a.alpha + (b.r * (1.0 - ratio)) * b.alpha;
	color.g = (a.g * ratio) * a.alpha + (b.g * (1.0 - ratio)) * b.alpha;
	color.b = (a.b * ratio) * a.alpha + (b.b * (1.0 - ratio)) * b.alpha;
	color.alpha = 1.0f;
	return (color);
}

t_gradient		get_new_gradient(double min, double max, t_color start,
									t_color stop)
{
	t_gradient	gradient;

	if (max <= min)
	{
		max = 1.0;
		min = 0.0;
		if (MLX_HELPERS_DEBUG == 1)
			ft_putendl_fd("get_new_gradient: error, min upper max", 2);
	}
	gradient.min = (min > 1.0) ? 1.0 : (min < 0.0) ? 0.0 : min;
	gradient.max = (max > 1.0) ? 1.0 : (max < 0.0) ? 0.0 : max;
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

	color = get_new_color(0, 0, 0, 0.0f);
	ratio = (ratio > 1.0f) ? 1.0f : (ratio < 0.0f) ? 0.0f : ratio;
	it = lst;
	while (it != NULL)
	{
		gradcol = (t_gradient*)it->content;
		if (ratio >= gradcol->min && ratio <= gradcol->max)
		{
			perc = (ratio - gradcol->min) / (gradcol->max - gradcol->min);
			color = get_scalar(gradcol->start, gradcol->stop, perc);
			color.alpha = 1.0f;
			return (color);
		}
		it = it->next;
	}
	if (MLX_HELPERS_DEBUG == 1)
		ft_putendl_fd("get_gradient_color: could not find color", 2);
	return (color);
}

void			del_gradient_list(t_list **lst)
{
	while ((*lst) != NULL)
	{
		ft_lstpop(lst);
	}
}
