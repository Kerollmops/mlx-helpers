/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:42:32 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 00:21:38 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../mlx_helpers.h"

t_color			get_new_color(float r, float g, float b, float alpha)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.alpha = (alpha > 1.0f) ? 1.0f : (alpha < 0.0f) ? 0.0f : alpha;
	return (color);
}

t_color			add_color(t_color in, t_color add)
{
	t_color		out;

	out = get_scalar(in, out, in.alpha);
	add.r = (in.r > (255.0f - add.r)) ? 255.0f - in.r : add.r;
	add.g = (in.g > (255.0f - add.g)) ? 255.0f - in.g : add.g;
	add.b = (in.b > (255.0f - add.b)) ? 255.0f - in.b : add.b;
	add = get_scalar(add, in, add.alpha);
	out.r += add.r;
	out.g += add.g;
	out.b += add.b;
	return (out);
}

t_color			sub_color(t_color in, t_color add)
{
	t_color		out;

	out = get_scalar(in, out, in.alpha);
	add.r = (add.r > (255.0f - in.r)) ? in.r : add.r;
	add.g = (add.g > (255.0f - in.g)) ? in.g : add.g;
	add.b = (add.b > (255.0f - in.b)) ? in.b : add.b;
	add = get_scalar(add, in, add.alpha);
	out.r -= add.r;
	out.g -= add.g;
	out.b -= add.b;
	return (out);
}

t_color			color_hexa(int hexa)
{
	t_color		color;

	color.b = (hexa & 0xFF);
	color.g = (hexa & 0xFF00) >> 8;
	color.r = (hexa & 0xFF0000) >> 16;
	color.alpha = 1.0f;
	return (color);
}
