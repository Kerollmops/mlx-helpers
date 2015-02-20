/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:42:32 by crenault          #+#    #+#             */
/*   Updated: 2015/02/20 23:21:14 by crenault         ###   ########.fr       */
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

void			add_color(uchar r, uchar g, uchar b, t_color *out)
{
	r = (out->r > (255 - r)) ? 255 - out->r : r;
	g = (out->g > (255 - g)) ? 255 - out->g : g;
	b = (out->b > (255 - b)) ? 255 - out->b : b;
	out->r += r;
	out->g += g;
	out->b += b;
}

void			sub_color(uchar r, uchar g, uchar b, t_color *out)
{
	r = (r > (255 - out->r)) ? out->r : r;
	g = (g > (255 - out->g)) ? out->g : g;
	b = (b > (255 - out->b)) ? out->b : b;
	out->r -= r;
	out->g -= g;
	out->b -= b;
}

t_color			color_hexa(int hexa)
{
	t_color		color;

	color.b = (hexa & 0xFF);
	color.g = (hexa & 0xFF00) >> 8;
	color.r = (hexa & 0xFF0000) >> 16;
	return (color);
}
