/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 11:24:17 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 18:52:57 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void				draw_pixel_5_5(t_image *image)
{
	t_color		color;

	color = get_new_color(250, 125, 0); // pure orange
	put_pixel_image(image, get_new_pos(20, 20), color);
}

void				print_pixel_5_5(t_image *image)
{
	t_color		color;

	color = get_pixel_image(image, get_new_pos(20, 20));
	printf("%d, %d, %d\n", color.r, color.g, color.b);
}

void				draw_pixel_5_10(t_image *image)
{
	t_color			color;

	color = get_new_color(125, 125, 125);
	color = add_color(color, get_new_color(0, 255, 0));
	color = sub_color(color, get_new_color(255, 0, 0));
	put_pixel_image(image, get_new_pos(20, 25), color);
}