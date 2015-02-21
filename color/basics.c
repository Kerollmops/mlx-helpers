/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:42:32 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 18:52:04 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../mlx_helpers.h"

t_color			get_new_color(uchar r, uchar g, uchar b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color			add_color(t_color in, t_color add)
{
	t_color		out;

	out = in;
	add.r = (in.r > (255 - add.r)) ? 255 - in.r : add.r;
	add.g = (in.g > (255 - add.g)) ? 255 - in.g : add.g;
	add.b = (in.b > (255 - add.b)) ? 255 - in.b : add.b;
	out.r += add.r;
	out.g += add.g;
	out.b += add.b;
	return (out);
}

t_color			sub_color(t_color in, t_color add)
{
	t_color		out;

	out = in;
	add.r = (add.r > (255 - in.r)) ? in.r : add.r;
	add.g = (add.g > (255 - in.g)) ? in.g : add.g;
	add.b = (add.b > (255 - in.b)) ? in.b : add.b;
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
	return (color);
}
